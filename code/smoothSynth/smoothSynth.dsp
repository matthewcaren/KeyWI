import("stdfaust.lib");
freq = hslider("freq", 400, 20, 20000, 0.01);
gate = button("gate") : en.asr(0.003, 1, 0.05);
readpressure = hslider("breath[BELA: ANALOG_0]", 0, -1.35, 1, 0.001)*-1 - offset;
sensitivity = hslider("sensitivity[BELA: ANALOG_4]", 0.3, -0.6, 0.9, 0.01) : si.smoo;
offset = hslider("offset[BELA: ANALOG_5]", 0.1, 0, 0.4, 0.01) : si.smoo;
//PBup = hslider("PBup[BELA: ANALOG_1]", 0, 0, 50, 0.1) - 11 : si.smooth(0.9995) : max(0);  // FSR
//PBdown = hslider("PBdown[BELA: ANALOG_2]", 0, 0, 50, 0.1) - 11 : si.smooth(0.9995) : max(0);  // FSR

pressure = readpressure : si.smooth(0.999) : max(0);
breath = (readpressure - .05) / (1-sensitivity) : si.smooth(0.99995) : max(0);


lfo = os.osc(7)*(breath-1.2 : max(0))*25;

osc = os.triangle(freq+lfo) + os.triangle(freq*4 + lfo)*(0.2 + breath*breath*0.5) + os.triangle(freq*2 + lfo)*breath*0.7;

filter = fi.lowpass(4, en.ar(0.001, 0.3, gate)*130 + breath*2500+500);

process = osc*gate*0.05 : filter <: _,_;
