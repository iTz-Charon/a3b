
#define private		0
#define protected		1
#define public		2

#define true	1
#define false	0

#define VSoft		0
#define VArmor		1
#define VAir		2

class CfgPatches {
	class DDOPP_taserpack {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Weapons_F"};
	};
};

class CfgMods {
	class DDOPP_TaserMod {
		dir = "Expansion";
		name = "Taser Mod";
		hidePicture = 0;
		hideName = 1;
		action = "http://www.arma3.com";
	};
};
class Mode_SemiAuto;	// External class reference
class Mode_FullAuto;	// External class reference
class GrenadeLauncher;	// External class reference

class CfgAmmo {
	class BulletBase;	// External class reference
	
	class DDOPP_B_Taser : BulletBase {
		hit = 0.55;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_65_caseless";
		visibleFire = 5;	// how much is visible when this weapon is fired
		audibleFire = 8;
		cost = 1.2;
		airLock = "true";
		typicalSpeed = 820;
		caliber = 0.3;
		model = "\A3\Weapons_f\Data\bullettracer\tracer_red.p3d";
		tracerScale = 1.0;
		tracerStartTime = 0.05;
		tracerEndTime = 1;
		airFriction = -0.15;
		
		class CamShakeFire {
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
		
		class CamShakePlayerFire {
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
		
		class HitEffects {
			Hit_Blood = "ImpactBlood";
		};
	};
};

class CfgMagazines {
	class CA_Magazine;	// External class reference
	
	class DDOPP_Nothing : CA_Magazine {
		scope = protected;
		value = 0;
		displayName = "";
		model = "\ca\weapons\mag_univ.p3d";
		picture = "";
		modelSpecial = "";
		useAction = false;
		useActionTitle = "";
		reloadAction = "ManActReloadMagazine";
		ammo = "";
		count = 0;
		initSpeed = 900;
		selectionFireAnim = "zasleh";
		nameSound = "magazine";
		maxLeadSpeed = 23;	// max estimated speed km/h
	};
	
	class DDOPP_1Rnd_X26 : CA_Magazine {
		scope = public;
		model = "DDOPP_taserPack\taser_x26\DDOPP_x26_mag";
		picture = "\DDOPP_taserPack\taser_x26\m_x26.paa";
		type = 16;
		initSpeed = 85;
		ammo = "DDOPP_B_Taser";
		selectionFireAnim = "zasleh";
		count = 1;
		displayName = "X26 Cartridge";
		descriptionShort = "X26 Taser Stun Cartridge. Holds 1 round. Use in the X26 Taser.";
	};
	
	class DDOPP_3Rnd_X3 : CA_Magazine {
		scope = public;
		model = "DDOPP_taserPack\taser_x3\DDOPP_x3_mag";
		picture = "\DDOPP_taserPack\taser_x3\m_x3.paa";
		type = 16;
		initSpeed = 85;
		ammo = "DDOPP_B_Taser";
		selectionFireAnim = "zasleh";
		count = 3;
		displayName = "X3 Cartridges";
		descriptionShort = "X3 Set of 3 Taser Stun Cartridges. Holds 3 rounds. Use in the X3 Taser.";
	};
};

class CfgWeapons {
	class Pistol;	// External class reference
	
	class Drive_Stun : GrenadeLauncher {
		cursor = "";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		displayName = "Drive-Stun Mode";
		selectionFireAnim = "crackle";
		reloadTime = 3;
		sound[] = {"\DDOPP_taserPack\Taser_Hit.wav", 0.001, 1, 400};
		magazines[] = {"DDOPP_Nothing"};
		recoil = "recoil_empty";
		optics = false;
		muzzlePos = "usti hlavne";	// position and direction of muzzle
		muzzleEnd = "konec hlavne";
		UiPicture = "\CA\weapons\data\Ico\i_regular_CA.paa";
	};
	
	class DDOPP_X26 : Pistol {
		scope = public;
		modelOptics = "-";
		model = "DDOPP_taserPack\taser_x26\DDOPP_x26";
		displayName = "X26 Taser (Yellow)";
		picture = "\DDOPP_taserPack\taser_x26\w_x26";
		UiPicture = "\DDOPP_taserPack\taser_x26\w_x26";
		
		class Library {
			libTextDesc = "X26 Taser. Can keep human targets stunned up to 20 seconds.";
		};
		descriptionShort = "X26 Taser. Can keep human targets stunned up to 20 seconds.";
		discreteDistance[] = {10};
		discreteDistanceInitIndex = 0;
		dispersion = 0.02;
		recoil = "recoil_single_pistol_2outof3";
		recoilProne = "recoil_single_pistol_prone_2outof3";
		minRange = 0;
		minRangeProbab = 0.1;
		midRange = 10;
		midRangeProbab = 0.3;
		maxRange = 20;
		maxRangeProbab = 0.04;
		aiRateOfFire = 0.5;	// delay between shots at given distance
		aiRateOfFireDistance = 50;
		ffCount = 1;
		reloadTime = 0.1;
		autoReload = false;
		magazineReloadTime = 5;
		magazines[] = {"DDOPP_1Rnd_X26"};
		
		class Drive_Stun_Mode : Drive_Stun {};
		muzzles[] = {this, "Drive_Stun_Mode"};
		optics = true;
		cursor = "";
		cursoraim = "DDOPP_taserPack\data\taser_cursor.paa";
		cursorSize = 1;
		
		class FlashLight {
			ambient[] = {0.1, 0.1, 0.1, 1};
			angle = 30;
			brightness = 0.1;
			color[] = {0.9, 0.9, 0.7, 0.9};
			direction = "flash_pos";
			position = "flash_dir";
			scale[] = {1, 1, 0.5};
		};
		begin1[] = {"\DDOPP_taserPack\Taser_Shot.wav", 0.2, 1, 700};
		soundBegin[] = {"begin1", 0.333};
		drySound[] = {"\ca\Weapons\Data\Sound\T33_dry_v1", 0.01, 1, 20};
		reloadMagazineSound[] = {"\ca\Weapons\Data\Sound\pistol_reload", 0.1, 1, 20};
		class EventHandlers {
			Init = "[] execVM ""\DDOPP_taserPack\scripts\Init_Taser.sqf""";
		};
	};
	
	class DDOPP_X26_b : DDOPP_X26 {
		model = "DDOPP_taserPack\taser_x26\DDOPP_x26_b";
		displayName = "X26 Taser (Black)";
		picture = "\DDOPP_taserPack\taser_x26\w_x26_b";
		UiPicture = "\DDOPP_taserPack\taser_x26\w_x26_b";
	};
	
	class DDOPP_X3 : DDOPP_X26 {
		model = "DDOPP_taserPack\taser_x3\DDOPP_x3";
		displayName = "X3 Taser (Yellow)";
		picture = "\DDOPP_taserPack\taser_x3\w_x3";
		UiPicture = "\DDOPP_taserPack\taser_x3\w_x3";
		
		class Library {
			libTextDesc = "X3 Taser. Can keep human targets stunned up to 20 seconds. Can carry up to 3 cartridges.";
		};
		descriptionShort = "X3 Taser. Can keep human targets stunned up to 20 seconds. Can carry up to 3 cartridges.";
		reloadTime = 0.1;
		autoReload = false;
		magazineReloadTime = 5;
		magazines[] = {"DDOPP_3Rnd_X3"};
		
		class FlashLight {
			ambient[] = {0.1, 0.1, 0.1, 1};
			angle = 30;
			brightness = 0.1;
			color[] = {0.9, 0.9, 0.7, 0.9};
			direction = "flash_pos";
			position = "flash_dir";
			scale[] = {1, 1, 0.5};
		};
	};
	
	class DDOPP_X3_b : DDOPP_X3 {
		model = "DDOPP_taserPack\taser_x3\DDOPP_x3_b";
		displayName = "X3 Taser (Black)";
		picture = "\DDOPP_taserPack\taser_x3\w_x3_b";
		UiPicture = "\DDOPP_taserPack\taser_x3\w_x3_b";
	};
};

class CfgSounds {
	class taser_hit {
		sound[] = {"\DDOPP_taserPack\Taser_Hit.wav", 0.1, 1};
		name = "taser_hit";
		titles[] = {};
	};
	
	class taser_spark {
		sound[] = {"\DDOPP_taserPack\Taser_Spark.wav", 0.1, 1};
		name = "taser_spark";
		titles[] = {};
	};
};

