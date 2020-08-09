import("stdfaust.lib");
freq = hslider("freq", 400, 20, 20000, 0.01);
gate = button("gate") : en.asr(0.005, 1, 0.1);
readpressure = hslider("breath[BELA: ANALOG_0]", 0, -1.35, 1, 0.001)*-1 - offset;
sensitivity = hslider("sensitivity[BELA: ANALOG_4]", 0.3, -0.6, 0.9, 0.01) : si.smoo;
offset = hslider("offset[BELA: ANALOG_5]", 0.1, 0, 0.4, 0.01) : si.smoo;
//PBup = hslider("PBup[BELA: ANALOG_1]", 0, 0, 50, 0.1) - 11 : si.smooth(0.9995) : max(0);  // FSR
//PBdown = hslider("PBdown[BELA: ANALOG_2]", 0, 0, 50, 0.1) - 11 : si.smooth(0.9995) : max(0);  // FSR

pGate = gate : en.ar(0.03, 0.3)*pressure*(pressure - 0.3 : max(0))*0.1;

pressure = readpressure : si.smooth(0.99988) : max(0);
breath = (readpressure + pGate - .05) / (1-sensitivity) : si.smooth(0.996) : max(0);

process = pm.brassModel(freq : pm.f2l,0.5,0.5,breath*gate*0.088)*0.6 <: _,_;
