import("stdfaust.lib");
verb = re.zita_rev1_stereo(60,200,6000,2.5,2,44100);
process = _,_ <: verb, (_,_) :> _,_;
