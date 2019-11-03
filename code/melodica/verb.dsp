import("stdfaust.lib");
verb = re.zita_rev1_stereo(60,200,6000,2.5,2,44100) : (_*0.25, _*0.25);
process = _,_ <: verb, (_,_) :> _,_;
