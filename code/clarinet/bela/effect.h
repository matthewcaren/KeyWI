/* ------------------------------------------------------------
name: "verb"
Code generated with Faust 2.17.13 (https://faust.grame.fr)
Compilation options: -lang cpp -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __effect_H__
#define  __effect_H__

/************************************************************************
 IMPORTANT NOTE : this file contains two clearly delimited sections :
 the ARCHITECTURE section (in two parts) and the USER section. Each section
 is governed by its own copyright and license. Please check individually
 each section for license and copyright information.
 *************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2019 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 
 ************************************************************************
 ************************************************************************/
 
#include <math.h>
#include <algorithm>

/************************** BEGIN UI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __UI_H__
#define __UI_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

struct Soundfile;

template <typename REAL>
class UIReal
{
    
    public:
        
        UIReal() {}
        virtual ~UIReal() {}
        
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;
        
        // -- active widgets
        
        virtual void addButton(const char* label, REAL* zone) = 0;
        virtual void addCheckButton(const char* label, REAL* zone) = 0;
        virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
        virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
        virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
        
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
        virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
        
        // -- soundfiles
        
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;
        
        // -- metadata declarations
        
        virtual void declare(REAL* zone, const char* key, const char* val) {}
};

class UI : public UIReal<FAUSTFLOAT>
{

    public:

        UI() {}
        virtual ~UI() {}
};

#endif
/**************************  END  UI.h **************************/
/************************** BEGIN meta.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __meta__
#define __meta__

struct Meta
{
    virtual ~Meta() {};
    virtual void declare(const char* key, const char* value) = 0;
    
};

#endif
/**************************  END  meta.h **************************/
/************************** BEGIN dsp.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>
#include <vector>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

/**
 * DSP memory manager.
 */

struct dsp_memory_manager {
    
    virtual ~dsp_memory_manager() {}
    
    virtual void* allocate(size_t size) = 0;
    virtual void destroy(void* ptr) = 0;
    
};

/**
* Signal processor definition.
*/

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the ui_interface parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /**
         * Global init, calls the following methods:
         * - static class 'classInit': static tables initialization
         * - 'instanceInit': constants and instance state initialization
         *
         * @param sample_rate - the sampling rate in Hertz
         */
        virtual void init(int sample_rate) = 0;

        /**
         * Init instance state
         *
         * @param sample_rate - the sampling rate in Hertz
         */
        virtual void instanceInit(int sample_rate) = 0;

        /**
         * Init instance constant state
         *
         * @param sample_rate - the sampling rate in Hertz
         */
        virtual void instanceConstants(int sample_rate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (delay lines...) */
        virtual void instanceClear() = 0;
 
        /**
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value) metadata.
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with successive in/out audio buffers.
         *
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         *
         */
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int sample_rate) { fDSP->init(sample_rate); }
        virtual void instanceInit(int sample_rate) { fDSP->instanceInit(sample_rate); }
        virtual void instanceConstants(int sample_rate) { fDSP->instanceConstants(sample_rate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
    
};

/**
 * DSP factory class.
 */

class dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        virtual ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
        virtual std::string getCompileOptions() = 0;
        virtual std::vector<std::string> getLibraryList() = 0;
        virtual std::vector<std::string> getIncludePathnames() = 0;
    
        virtual dsp* createDSPInstance() = 0;
    
        virtual void setMemoryManager(dsp_memory_manager* manager) = 0;
        virtual dsp_memory_manager* getMemoryManager() = 0;
    
};

/**
 * On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
 * flags to avoid costly denormals.
 */

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif
/**************************  END  dsp.h **************************/

using std::max;
using std::min;

/******************************************************************************
 *******************************************************************************
 
 VECTOR INTRINSICS
 
 *******************************************************************************
 *******************************************************************************/


/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>

static float effect_faustpower2_f(float value) {
	return (value * value);
	
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS effect
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class effect : public dsp {
	
 private:
	
	int IOTA;
	float fVec0[16384];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	float fConst3;
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	float fConst15;
	float fRec11[2];
	float fRec10[2];
	float fVec1[32768];
	float fConst16;
	int iConst17;
	float fVec2[16384];
	int iConst18;
	float fVec3[2048];
	int iConst19;
	float fRec8[2];
	float fConst20;
	float fConst21;
	float fConst22;
	float fConst23;
	float fConst24;
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fConst29;
	float fConst30;
	float fRec15[2];
	float fRec14[2];
	float fVec4[32768];
	float fConst31;
	int iConst32;
	float fVec5[4096];
	int iConst33;
	float fRec12[2];
	float fConst34;
	float fConst35;
	float fConst36;
	float fConst37;
	float fConst38;
	float fConst39;
	float fConst40;
	float fConst41;
	float fConst42;
	float fConst43;
	float fConst44;
	float fRec19[2];
	float fRec18[2];
	float fVec6[16384];
	float fConst45;
	int iConst46;
	float fVec7[4096];
	int iConst47;
	float fRec16[2];
	float fConst48;
	float fConst49;
	float fConst50;
	float fConst51;
	float fConst52;
	float fConst53;
	float fConst54;
	float fConst55;
	float fConst56;
	float fConst57;
	float fConst58;
	float fRec23[2];
	float fRec22[2];
	float fVec8[32768];
	float fConst59;
	int iConst60;
	float fVec9[4096];
	int iConst61;
	float fRec20[2];
	float fConst62;
	float fConst63;
	float fConst64;
	float fConst65;
	float fConst66;
	float fConst67;
	float fConst68;
	float fConst69;
	float fConst70;
	float fConst71;
	float fConst72;
	float fRec27[2];
	float fRec26[2];
	float fVec10[16384];
	float fConst73;
	int iConst74;
	float fVec11[2048];
	int iConst75;
	float fRec24[2];
	float fConst76;
	float fConst77;
	float fConst78;
	float fConst79;
	float fConst80;
	float fConst81;
	float fConst82;
	float fConst83;
	float fConst84;
	float fConst85;
	float fConst86;
	float fRec31[2];
	float fRec30[2];
	float fVec12[16384];
	float fConst87;
	int iConst88;
	float fVec13[4096];
	int iConst89;
	float fRec28[2];
	float fConst90;
	float fConst91;
	float fConst92;
	float fConst93;
	float fConst94;
	float fConst95;
	float fConst96;
	float fConst97;
	float fConst98;
	float fConst99;
	float fConst100;
	float fRec35[2];
	float fRec34[2];
	float fVec14[16384];
	float fConst101;
	int iConst102;
	float fVec15[2048];
	int iConst103;
	float fRec32[2];
	float fConst104;
	float fConst105;
	float fConst106;
	float fConst107;
	float fConst108;
	float fConst109;
	float fConst110;
	float fConst111;
	float fConst112;
	float fConst113;
	float fConst114;
	float fRec39[2];
	float fRec38[2];
	float fVec16[16384];
	float fConst115;
	int iConst116;
	float fVec17[2048];
	int iConst117;
	float fRec36[2];
	float fRec0[3];
	float fRec1[3];
	float fRec2[3];
	float fRec3[3];
	float fRec4[3];
	float fRec5[3];
	float fRec6[3];
	float fRec7[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "verb.dsp");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "verb");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "0.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.1");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 2;
		
	}
	virtual int getNumOutputs() {
		return 2;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int sample_rate) {
		
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = std::floor(((0.219990999f * fConst0) + 0.5f));
		fConst2 = ((0.0f - (6.90775537f * fConst1)) / fConst0);
		fConst3 = std::exp((0.5f * fConst2));
		fConst4 = effect_faustpower2_f(fConst3);
		fConst5 = std::cos((37699.1133f / fConst0));
		fConst6 = (1.0f - (fConst4 * fConst5));
		fConst7 = (1.0f - fConst4);
		fConst8 = (fConst6 / fConst7);
		fConst9 = std::sqrt(std::max<float>(0.0f, ((effect_faustpower2_f(fConst6) / effect_faustpower2_f(fConst7)) + -1.0f)));
		fConst10 = (fConst8 - fConst9);
		fConst11 = (fConst3 * (fConst9 + (1.0f - fConst8)));
		fConst12 = ((std::exp((0.400000006f * fConst2)) / fConst3) + -1.0f);
		fConst13 = (1.0f / std::tan((628.318542f / fConst0)));
		fConst14 = (1.0f / (fConst13 + 1.0f));
		fConst15 = (1.0f - fConst13);
		fConst16 = std::floor(((0.0191229992f * fConst0) + 0.5f));
		iConst17 = int(std::min<float>(16384.0f, std::max<float>(0.0f, (fConst1 - fConst16))));
		iConst18 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (0.0599999987f * fConst0))));
		iConst19 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst16 + -1.0f))));
		fConst20 = std::floor(((0.256891012f * fConst0) + 0.5f));
		fConst21 = ((0.0f - (6.90775537f * fConst20)) / fConst0);
		fConst22 = std::exp((0.5f * fConst21));
		fConst23 = effect_faustpower2_f(fConst22);
		fConst24 = (1.0f - (fConst23 * fConst5));
		fConst25 = (1.0f - fConst23);
		fConst26 = (fConst24 / fConst25);
		fConst27 = std::sqrt(std::max<float>(0.0f, ((effect_faustpower2_f(fConst24) / effect_faustpower2_f(fConst25)) + -1.0f)));
		fConst28 = (fConst26 - fConst27);
		fConst29 = (fConst22 * (fConst27 + (1.0f - fConst26)));
		fConst30 = ((std::exp((0.400000006f * fConst21)) / fConst22) + -1.0f);
		fConst31 = std::floor(((0.0273330007f * fConst0) + 0.5f));
		iConst32 = int(std::min<float>(16384.0f, std::max<float>(0.0f, (fConst20 - fConst31))));
		iConst33 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst31 + -1.0f))));
		fConst34 = std::floor(((0.192303002f * fConst0) + 0.5f));
		fConst35 = ((0.0f - (6.90775537f * fConst34)) / fConst0);
		fConst36 = std::exp((0.5f * fConst35));
		fConst37 = effect_faustpower2_f(fConst36);
		fConst38 = (1.0f - (fConst37 * fConst5));
		fConst39 = (1.0f - fConst37);
		fConst40 = (fConst38 / fConst39);
		fConst41 = std::sqrt(std::max<float>(0.0f, ((effect_faustpower2_f(fConst38) / effect_faustpower2_f(fConst39)) + -1.0f)));
		fConst42 = (fConst40 - fConst41);
		fConst43 = (fConst36 * (fConst41 + (1.0f - fConst40)));
		fConst44 = ((std::exp((0.400000006f * fConst35)) / fConst36) + -1.0f);
		fConst45 = std::floor(((0.0292910002f * fConst0) + 0.5f));
		iConst46 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst34 - fConst45))));
		iConst47 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst45 + -1.0f))));
		fConst48 = std::floor(((0.210389003f * fConst0) + 0.5f));
		fConst49 = ((0.0f - (6.90775537f * fConst48)) / fConst0);
		fConst50 = std::exp((0.5f * fConst49));
		fConst51 = effect_faustpower2_f(fConst50);
		fConst52 = (1.0f - (fConst51 * fConst5));
		fConst53 = (1.0f - fConst51);
		fConst54 = (fConst52 / fConst53);
		fConst55 = std::sqrt(std::max<float>(0.0f, ((effect_faustpower2_f(fConst52) / effect_faustpower2_f(fConst53)) + -1.0f)));
		fConst56 = (fConst54 - fConst55);
		fConst57 = (fConst50 * (fConst55 + (1.0f - fConst54)));
		fConst58 = ((std::exp((0.400000006f * fConst49)) / fConst50) + -1.0f);
		fConst59 = std::floor(((0.0244210009f * fConst0) + 0.5f));
		iConst60 = int(std::min<float>(16384.0f, std::max<float>(0.0f, (fConst48 - fConst59))));
		iConst61 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst59 + -1.0f))));
		fConst62 = std::floor(((0.125f * fConst0) + 0.5f));
		fConst63 = ((0.0f - (6.90775537f * fConst62)) / fConst0);
		fConst64 = std::exp((0.5f * fConst63));
		fConst65 = effect_faustpower2_f(fConst64);
		fConst66 = (1.0f - (fConst65 * fConst5));
		fConst67 = (1.0f - fConst65);
		fConst68 = (fConst66 / fConst67);
		fConst69 = std::sqrt(std::max<float>(0.0f, ((effect_faustpower2_f(fConst66) / effect_faustpower2_f(fConst67)) + -1.0f)));
		fConst70 = (fConst68 - fConst69);
		fConst71 = (fConst64 * (fConst69 + (1.0f - fConst68)));
		fConst72 = ((std::exp((0.400000006f * fConst63)) / fConst64) + -1.0f);
		fConst73 = std::floor(((0.0134579996f * fConst0) + 0.5f));
		iConst74 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst62 - fConst73))));
		iConst75 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst73 + -1.0f))));
		fConst76 = std::floor(((0.127837002f * fConst0) + 0.5f));
		fConst77 = ((0.0f - (6.90775537f * fConst76)) / fConst0);
		fConst78 = std::exp((0.5f * fConst77));
		fConst79 = effect_faustpower2_f(fConst78);
		fConst80 = (1.0f - (fConst79 * fConst5));
		fConst81 = (1.0f - fConst79);
		fConst82 = (fConst80 / fConst81);
		fConst83 = std::sqrt(std::max<float>(0.0f, ((effect_faustpower2_f(fConst80) / effect_faustpower2_f(fConst81)) + -1.0f)));
		fConst84 = (fConst82 - fConst83);
		fConst85 = (fConst78 * (fConst83 + (1.0f - fConst82)));
		fConst86 = ((std::exp((0.400000006f * fConst77)) / fConst78) + -1.0f);
		fConst87 = std::floor(((0.0316039994f * fConst0) + 0.5f));
		iConst88 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst76 - fConst87))));
		iConst89 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst87 + -1.0f))));
		fConst90 = std::floor(((0.174713001f * fConst0) + 0.5f));
		fConst91 = ((0.0f - (6.90775537f * fConst90)) / fConst0);
		fConst92 = std::exp((0.5f * fConst91));
		fConst93 = effect_faustpower2_f(fConst92);
		fConst94 = (1.0f - (fConst93 * fConst5));
		fConst95 = (1.0f - fConst93);
		fConst96 = (fConst94 / fConst95);
		fConst97 = std::sqrt(std::max<float>(0.0f, ((effect_faustpower2_f(fConst94) / effect_faustpower2_f(fConst95)) + -1.0f)));
		fConst98 = (fConst96 - fConst97);
		fConst99 = (fConst92 * (fConst97 + (1.0f - fConst96)));
		fConst100 = ((std::exp((0.400000006f * fConst91)) / fConst92) + -1.0f);
		fConst101 = std::floor(((0.0229039993f * fConst0) + 0.5f));
		iConst102 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst90 - fConst101))));
		iConst103 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst101 + -1.0f))));
		fConst104 = std::floor(((0.153128996f * fConst0) + 0.5f));
		fConst105 = ((0.0f - (6.90775537f * fConst104)) / fConst0);
		fConst106 = std::exp((0.5f * fConst105));
		fConst107 = effect_faustpower2_f(fConst106);
		fConst108 = (1.0f - (fConst107 * fConst5));
		fConst109 = (1.0f - fConst107);
		fConst110 = (fConst108 / fConst109);
		fConst111 = std::sqrt(std::max<float>(0.0f, ((effect_faustpower2_f(fConst108) / effect_faustpower2_f(fConst109)) + -1.0f)));
		fConst112 = (fConst110 - fConst111);
		fConst113 = (fConst106 * (fConst111 + (1.0f - fConst110)));
		fConst114 = ((std::exp((0.400000006f * fConst105)) / fConst106) + -1.0f);
		fConst115 = std::floor(((0.0203460008f * fConst0) + 0.5f));
		iConst116 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst104 - fConst115))));
		iConst117 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst115 + -1.0f))));
		
	}
	
	virtual void instanceResetUserInterface() {
		
	}
	
	virtual void instanceClear() {
		IOTA = 0;
		for (int l0 = 0; (l0 < 16384); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec11[l1] = 0.0f;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec10[l2] = 0.0f;
			
		}
		for (int l3 = 0; (l3 < 32768); l3 = (l3 + 1)) {
			fVec1[l3] = 0.0f;
			
		}
		for (int l4 = 0; (l4 < 16384); l4 = (l4 + 1)) {
			fVec2[l4] = 0.0f;
			
		}
		for (int l5 = 0; (l5 < 2048); l5 = (l5 + 1)) {
			fVec3[l5] = 0.0f;
			
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec8[l6] = 0.0f;
			
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec15[l7] = 0.0f;
			
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec14[l8] = 0.0f;
			
		}
		for (int l9 = 0; (l9 < 32768); l9 = (l9 + 1)) {
			fVec4[l9] = 0.0f;
			
		}
		for (int l10 = 0; (l10 < 4096); l10 = (l10 + 1)) {
			fVec5[l10] = 0.0f;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec12[l11] = 0.0f;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec19[l12] = 0.0f;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec18[l13] = 0.0f;
			
		}
		for (int l14 = 0; (l14 < 16384); l14 = (l14 + 1)) {
			fVec6[l14] = 0.0f;
			
		}
		for (int l15 = 0; (l15 < 4096); l15 = (l15 + 1)) {
			fVec7[l15] = 0.0f;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec16[l16] = 0.0f;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec23[l17] = 0.0f;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec22[l18] = 0.0f;
			
		}
		for (int l19 = 0; (l19 < 32768); l19 = (l19 + 1)) {
			fVec8[l19] = 0.0f;
			
		}
		for (int l20 = 0; (l20 < 4096); l20 = (l20 + 1)) {
			fVec9[l20] = 0.0f;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec20[l21] = 0.0f;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec27[l22] = 0.0f;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec26[l23] = 0.0f;
			
		}
		for (int l24 = 0; (l24 < 16384); l24 = (l24 + 1)) {
			fVec10[l24] = 0.0f;
			
		}
		for (int l25 = 0; (l25 < 2048); l25 = (l25 + 1)) {
			fVec11[l25] = 0.0f;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec24[l26] = 0.0f;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec31[l27] = 0.0f;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec30[l28] = 0.0f;
			
		}
		for (int l29 = 0; (l29 < 16384); l29 = (l29 + 1)) {
			fVec12[l29] = 0.0f;
			
		}
		for (int l30 = 0; (l30 < 4096); l30 = (l30 + 1)) {
			fVec13[l30] = 0.0f;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec28[l31] = 0.0f;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec35[l32] = 0.0f;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec34[l33] = 0.0f;
			
		}
		for (int l34 = 0; (l34 < 16384); l34 = (l34 + 1)) {
			fVec14[l34] = 0.0f;
			
		}
		for (int l35 = 0; (l35 < 2048); l35 = (l35 + 1)) {
			fVec15[l35] = 0.0f;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec32[l36] = 0.0f;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec39[l37] = 0.0f;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec38[l38] = 0.0f;
			
		}
		for (int l39 = 0; (l39 < 16384); l39 = (l39 + 1)) {
			fVec16[l39] = 0.0f;
			
		}
		for (int l40 = 0; (l40 < 2048); l40 = (l40 + 1)) {
			fVec17[l40] = 0.0f;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec36[l41] = 0.0f;
			
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec0[l42] = 0.0f;
			
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec1[l43] = 0.0f;
			
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec2[l44] = 0.0f;
			
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec3[l45] = 0.0f;
			
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec4[l46] = 0.0f;
			
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec5[l47] = 0.0f;
			
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec6[l48] = 0.0f;
			
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec7[l49] = 0.0f;
			
		}
		
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual effect* clone() {
		return new effect();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("verb");
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		for (int i = 0; (i < count); i = (i + 1)) {
			float fTemp0 = float(input0[i]);
			fVec0[(IOTA & 16383)] = fTemp0;
			fRec11[0] = (0.0f - (fConst14 * ((fConst15 * fRec11[1]) - (fRec7[1] + fRec7[2]))));
			fRec10[0] = ((fConst10 * fRec10[1]) + (fConst11 * (fRec7[1] + (fConst12 * fRec11[0]))));
			fVec1[(IOTA & 32767)] = ((0.353553385f * fRec10[0]) + 9.99999968e-21f);
			float fTemp1 = float(input1[i]);
			fVec2[(IOTA & 16383)] = fTemp1;
			float fTemp2 = (0.300000012f * fVec2[((IOTA - iConst18) & 16383)]);
			float fTemp3 = (((0.600000024f * fRec8[1]) + fVec1[((IOTA - iConst17) & 32767)]) - fTemp2);
			fVec3[(IOTA & 2047)] = fTemp3;
			fRec8[0] = fVec3[((IOTA - iConst19) & 2047)];
			float fRec9 = (0.0f - (0.600000024f * fTemp3));
			fRec15[0] = (0.0f - (fConst14 * ((fConst15 * fRec15[1]) - (fRec3[1] + fRec3[2]))));
			fRec14[0] = ((fConst28 * fRec14[1]) + (fConst29 * (fRec3[1] + (fConst30 * fRec15[0]))));
			fVec4[(IOTA & 32767)] = ((0.353553385f * fRec14[0]) + 9.99999968e-21f);
			float fTemp4 = (((0.600000024f * fRec12[1]) + fVec4[((IOTA - iConst32) & 32767)]) - fTemp2);
			fVec5[(IOTA & 4095)] = fTemp4;
			fRec12[0] = fVec5[((IOTA - iConst33) & 4095)];
			float fRec13 = (0.0f - (0.600000024f * fTemp4));
			fRec19[0] = (0.0f - (fConst14 * ((fConst15 * fRec19[1]) - (fRec5[1] + fRec5[2]))));
			fRec18[0] = ((fConst42 * fRec18[1]) + (fConst43 * (fRec5[1] + (fConst44 * fRec19[0]))));
			fVec6[(IOTA & 16383)] = ((0.353553385f * fRec18[0]) + 9.99999968e-21f);
			float fTemp5 = (fVec6[((IOTA - iConst46) & 16383)] + (fTemp2 + (0.600000024f * fRec16[1])));
			fVec7[(IOTA & 4095)] = fTemp5;
			fRec16[0] = fVec7[((IOTA - iConst47) & 4095)];
			float fRec17 = (0.0f - (0.600000024f * fTemp5));
			fRec23[0] = (0.0f - (fConst14 * ((fConst15 * fRec23[1]) - (fRec1[1] + fRec1[2]))));
			fRec22[0] = ((fConst56 * fRec22[1]) + (fConst57 * (fRec1[1] + (fConst58 * fRec23[0]))));
			fVec8[(IOTA & 32767)] = ((0.353553385f * fRec22[0]) + 9.99999968e-21f);
			float fTemp6 = (fTemp2 + ((0.600000024f * fRec20[1]) + fVec8[((IOTA - iConst60) & 32767)]));
			fVec9[(IOTA & 4095)] = fTemp6;
			fRec20[0] = fVec9[((IOTA - iConst61) & 4095)];
			float fRec21 = (0.0f - (0.600000024f * fTemp6));
			fRec27[0] = (0.0f - (fConst14 * ((fConst15 * fRec27[1]) - (fRec6[1] + fRec6[2]))));
			fRec26[0] = ((fConst70 * fRec26[1]) + (fConst71 * (fRec6[1] + (fConst72 * fRec27[0]))));
			fVec10[(IOTA & 16383)] = ((0.353553385f * fRec26[0]) + 9.99999968e-21f);
			float fTemp7 = (0.300000012f * fVec0[((IOTA - iConst18) & 16383)]);
			float fTemp8 = (fVec10[((IOTA - iConst74) & 16383)] - (fTemp7 + (0.600000024f * fRec24[1])));
			fVec11[(IOTA & 2047)] = fTemp8;
			fRec24[0] = fVec11[((IOTA - iConst75) & 2047)];
			float fRec25 = (0.600000024f * fTemp8);
			fRec31[0] = (0.0f - (fConst14 * ((fConst15 * fRec31[1]) - (fRec2[1] + fRec2[2]))));
			fRec30[0] = ((fConst84 * fRec30[1]) + (fConst85 * (fRec2[1] + (fConst86 * fRec31[0]))));
			fVec12[(IOTA & 16383)] = ((0.353553385f * fRec30[0]) + 9.99999968e-21f);
			float fTemp9 = (fVec12[((IOTA - iConst88) & 16383)] - (fTemp7 + (0.600000024f * fRec28[1])));
			fVec13[(IOTA & 4095)] = fTemp9;
			fRec28[0] = fVec13[((IOTA - iConst89) & 4095)];
			float fRec29 = (0.600000024f * fTemp9);
			fRec35[0] = (0.0f - (fConst14 * ((fConst15 * fRec35[1]) - (fRec4[1] + fRec4[2]))));
			fRec34[0] = ((fConst98 * fRec34[1]) + (fConst99 * (fRec4[1] + (fConst100 * fRec35[0]))));
			fVec14[(IOTA & 16383)] = ((0.353553385f * fRec34[0]) + 9.99999968e-21f);
			float fTemp10 = ((fTemp7 + fVec14[((IOTA - iConst102) & 16383)]) - (0.600000024f * fRec32[1]));
			fVec15[(IOTA & 2047)] = fTemp10;
			fRec32[0] = fVec15[((IOTA - iConst103) & 2047)];
			float fRec33 = (0.600000024f * fTemp10);
			fRec39[0] = (0.0f - (fConst14 * ((fConst15 * fRec39[1]) - (fRec0[1] + fRec0[2]))));
			fRec38[0] = ((fConst112 * fRec38[1]) + (fConst113 * (fRec0[1] + (fConst114 * fRec39[0]))));
			fVec16[(IOTA & 16383)] = ((0.353553385f * fRec38[0]) + 9.99999968e-21f);
			float fTemp11 = ((fVec16[((IOTA - iConst116) & 16383)] + fTemp7) - (0.600000024f * fRec36[1]));
			fVec17[(IOTA & 2047)] = fTemp11;
			fRec36[0] = fVec17[((IOTA - iConst117) & 2047)];
			float fRec37 = (0.600000024f * fTemp11);
			float fTemp12 = (fRec37 + fRec33);
			float fTemp13 = (fRec25 + (fRec29 + fTemp12));
			fRec0[0] = (fRec8[1] + (fRec12[1] + (fRec16[1] + (fRec20[1] + (fRec24[1] + (fRec28[1] + (fRec32[1] + (fRec36[1] + (fRec9 + (fRec13 + (fRec17 + (fRec21 + fTemp13))))))))))));
			fRec1[0] = ((fRec24[1] + (fRec28[1] + (fRec32[1] + (fRec36[1] + fTemp13)))) - (fRec8[1] + (fRec12[1] + (fRec16[1] + (fRec20[1] + (fRec9 + (fRec13 + (fRec21 + fRec17))))))));
			float fTemp14 = (fRec29 + fRec25);
			fRec2[0] = ((fRec16[1] + (fRec20[1] + (fRec32[1] + (fRec36[1] + (fRec17 + (fRec21 + fTemp12)))))) - (fRec8[1] + (fRec12[1] + (fRec24[1] + (fRec28[1] + (fRec9 + (fRec13 + fTemp14)))))));
			fRec3[0] = ((fRec8[1] + (fRec12[1] + (fRec32[1] + (fRec36[1] + (fRec9 + (fRec13 + fTemp12)))))) - (fRec16[1] + (fRec20[1] + (fRec24[1] + (fRec28[1] + (fRec17 + (fRec21 + fTemp14)))))));
			float fTemp15 = (fRec37 + fRec29);
			float fTemp16 = (fRec33 + fRec25);
			fRec4[0] = ((fRec12[1] + (fRec20[1] + (fRec28[1] + (fRec36[1] + (fRec13 + (fRec21 + fTemp15)))))) - (fRec8[1] + (fRec16[1] + (fRec24[1] + (fRec32[1] + (fRec9 + (fRec17 + fTemp16)))))));
			fRec5[0] = ((fRec8[1] + (fRec16[1] + (fRec28[1] + (fRec36[1] + (fRec9 + (fRec17 + fTemp15)))))) - (fRec12[1] + (fRec20[1] + (fRec24[1] + (fRec32[1] + (fRec13 + (fRec21 + fTemp16)))))));
			float fTemp17 = (fRec37 + fRec25);
			float fTemp18 = (fRec33 + fRec29);
			fRec6[0] = ((fRec8[1] + (fRec20[1] + (fRec24[1] + (fRec36[1] + (fRec9 + (fRec21 + fTemp17)))))) - (fRec12[1] + (fRec16[1] + (fRec28[1] + (fRec32[1] + (fRec13 + (fRec17 + fTemp18)))))));
			fRec7[0] = ((fRec12[1] + (fRec16[1] + (fRec24[1] + (fRec36[1] + (fRec13 + (fRec17 + fTemp17)))))) - (fRec8[1] + (fRec20[1] + (fRec28[1] + (fRec32[1] + (fRec9 + (fRec21 + fTemp18)))))));
			output0[i] = FAUSTFLOAT((fTemp0 + (0.370000005f * (fRec1[0] + fRec2[0]))));
			output1[i] = FAUSTFLOAT((fTemp1 + (0.370000005f * (fRec1[0] - fRec2[0]))));
			IOTA = (IOTA + 1);
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fRec8[1] = fRec8[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec12[1] = fRec12[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec20[1] = fRec20[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec32[1] = fRec32[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec36[1] = fRec36[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			
		}
		
	}

};

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

/********************END ARCHITECTURE SECTION (part 2/2)****************/


#endif
