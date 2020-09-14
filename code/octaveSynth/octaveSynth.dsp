import("stdfaust.lib");
freq = hslider("freq", 400, 20, 20000, 0.01);
gate = button("gate") : en.asr(0.003, 1, 0.04);
readpressure = hslider("breath[BELA: ANALOG_0]", 0, -1.35, 1, 0.001)*-1 - offset;
sensitivity = hslider("sensitivity[BELA: ANALOG_4]", 0.3, -0.6, 0.9, 0.01) : si.smoo;
offset = hslider("offset[BELA: ANALOG_5]", 0.1, 0, 0.4, 0.01) : si.smoo;
//PBup = hslider("PBup[BELA: ANALOG_1]", 0, 0, 50, 0.1) - 11 : si.smooth(0.9995) : max(0);  // FSR
//PBdown = hslider("PBdown[BELA: ANALOG_2]", 0, 0, 50, 0.1) - 11 : si.smooth(0.9995) : max(0);  // FSR

pressure = readpressure : si.smooth(0.999) : max(0);
breath = (readpressure - .05) / (1-sensitivity) : si.smooth(0.99995) : max(0);


osc = os.sawtooth(freq*0.25) + os.sawtooth(freq*.998)*0.5 + os.sawtooth(freq*1.002)*0.5;

filter = fi.lowpass(3, en.adsre(0.03,0.7,0.1, 0.5, gate)*3500 + breath*8000+20);

process = osc*gate*0.02 : filter <: _,_;
