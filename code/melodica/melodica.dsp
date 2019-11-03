import("stdfaust.lib");
freq = hslider("freq", 932.33, 200, 1500, 0.01);
gate = button("gate") : en.asr(0.01, 1, 0.05);
readpressure = hslider("breath[BELA: ANALOG_0]", 0, -1, 1, 0.001);  // MPX
sensitivity = hslider("sensitivity[BELA: ANALOG_1]", 0.3, -0.6, 0.9, 0.01) : si.smoo;  // 10k pot
PBup = hslider("PBup[BELA: ANALOG_2]", 0, 0, 50, 0.1) - 11 : si.smooth(0.9995) : max(0);  // FSR
//PBdown = hslider("PBdown[BELA: ANALOG_3]", 0, 0, 50, 0.1) - 11 : si.smooth(0.9995) : max(0);  // FSR
//vibrato = hslider("vibrato[BELA: ANALOG_4]", 0, 0, 5, 0.01) - 3 : si.smooth(0.99995) : max(0);  // FSR

pressure = readpressure : si.smooth(0.998) : max(0);
pGate = gate : en.ar(0.015, 0.2)*pressure;
breath = (readpressure + pGate - .05) / (1-sensitivity) : si.smooth(0.998) : max(0);


// clip from 2.75 to 3.5
clip = breath*0.8+2.75;

fs = hslider("fundamental subtract", 0.6, 0, 3, 0.01) : si.smoo;

vibratoOsc = os.osc(4);

//sine = os.osc(freq + PBup - PBdown + vibratoOsc*vibrato);
sine = os.osc(freq + PBup);
reed = (((((sine*clip*2 -1) : ef.cubicnl(0,0))+1)/2 + (sine*2+1 : ef.cubicnl(0,0)-1)*0.1 -sine*fs)-breath/3)*breath*gate : fi.lowpass(2, 8000);

noise = gate : ba.impulsify : en.ar(0.005, 0.1) : (_ + 0.2) *no.pink_noise*pressure : fi.highpass(2, 900);

process = (reed + noise*0.15)/5 <: _,_;
