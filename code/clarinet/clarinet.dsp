import("stdfaust.lib");
freq = hslider("freq", 400, 50, 10000, 0.01);
gate = button("gate") : en.asr(0.01, 1, 0.17);
sensitivity = hslider("sensitivity[BELA: ANALOG_1]", 0.7, 0.3, 0.95, 0.01) : si.smoo;
breath = (hslider("breath[BELA: ANALOG_0]", 0, -1, 1, 0.001) - 0.2) / (1-sensitivity) : si.smooth(0.99) : max(0) : min(1);
//vibrato = hslider("vibrato[BELA: ANALOG_2]", 0, 0, 0.02, 0.001) - 0.015 : si.smooth(0.99995) : max(0);
//process = pm.clarinetModel(freq : pm.f2l + os.osc(4)*vibrato, breath*gate, 0.65, 0.5)*0.05 <: _,_;
pb = hslider("pb[BELA: ANALOG_2]", 0, 0, 0.06, 0.001) - 0.035 : si.smooth(0.9999) : max(0);
process = pm.clarinetModel(freq : pm.f2l + pb, breath*gate, 0.65, 0.5)*0.05 <: _,_;
