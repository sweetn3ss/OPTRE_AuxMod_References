class cfgPatches // don't change this
{
	class my_mod // change this to whatever you like, preferably organize your pbos by what's in them
	{
		author="me"; // change this to either your name or your unit's name
		weapons[]={}; // every helmet, weapon, vest, and nvg in your mod
		units[]={}; // unnecessary unless you're putting in ai units, uniforms, or vehicles(backpacks are vehicles)
		magazines[]={}; // magazines isn't actually read by arma on unpackage, so don't worry about this one
		ammo[]={}; // this isn't read either lol
		requiredAddons[]= // this points arma and some packaging software to what pbo needs to be read for this to work. if you don't use advanced packaging software, you can ignore this.
		{
			"OPTRE_UNSC_Units"
		};
		requiredVersion=0.1; // no idea what the fuck this is for; leave it as 0.1
	};
};

class cfgWeapons
{
	// first i'm going to put in what i need to inherit from. for this, i'll only worry about helmets and vests right now.
	class OPTRE_UNSC_CH252D_Helmet; // base ODST helmet for example
	class OPTRE_UNSC_CH252D_Helmet_dp; // the comments i'm leaving will explain this in a bit
	class OPTRE_UNSC_M52A_Armor_Base; // OPTRE's "absolute" m52a
	class VestItem; // this is only used for vests when they need their ItemInfo defined at some point. in some cases, this can be replaced with ItemInfo for inheritence to no consequence.
	class HeadgearItem; // used for ItemInfo inheritance in helmets, as you probably guessed from the above lol
	
	// here begins the actual object definitions of this config. the classname before the colon, or ":" is the one that the object being created uses. the one after is where it inherits from. be careful of typos!!!
	class my_default_vest: OPTRE_UNSC_M52A_Armor_Base // this is the example vest we'll be touching on
	{
		dlc="my cool mod!"; // this is strictly optional. afaik, can be ignored outright if you want
		scope=1; // scope=0; means it cannot be in game, but can be inherited from. scope=1; means it can exist if it's forced to, scope=2; means it will show up of its own volition
		scopeArsenal=1; // same as above but for showing up in arsenal
		scopeCurator=1; // same as above but for zeus and eden editor
		author="Mesa"; // name that shows up for who made this thing. sometimes doesn't work.
		displayName="-"; // the name that the item has in game. i've set this one to "-" because this item isn't intended to show up in game at all, but just be something for absolute values to be drawn from.
		picture="\OPTRE_UNSC_Units\Army\icons\Army_vest_wdl.paa"; // icon in arsenal and inventory.
		model="\OPTRE_UNSC_Units\Army\armor.p3d"; // model used for the item when worn or dropped on the ground.
		hiddenSelections[]= // these are used to either feed something a texture, or toggle a cosmetic section on or off. if the hiddenSelection is not deleted or commented out, it will not show up.(except for camos with a filepath attributed to them)
		{
			"camo", // these hiddenSelections until camo5 are what the textures in hiddenSelectionsTextures use to direct their textures to the proper mesh/vertex group. fancy talk for "this is the picture it uses in game for how it looks"
			"camo2",
			"camo3",
			"camo4",
			"camo5",
			"A_Base",
			"A_ChestArmor",
			"A_Ghillie",
			"A_KneesLeft",
			"A_KneesRight",
			"A_KneesMarLeft",
			"A_KneesMarRight",
			"A_ODST",
			"A_ShinArmorLeft",
			"A_ShinArmorRight",
			"A_TacPad",
			"A_ThighArmorLeft",
			"A_ThighArmorRight",
			"AS_BaseLeft",
			"AS_BaseRight",
			"AS_LargeLeft",
			"AS_LargeRight",
			"AS_MediumLeft",
			"AS_MediumRight",
			"AS_ODSTCQBLeft",
			"AS_ODSTCQBRight",
			"AS_ODSTLeft",
			"AS_ODSTRight",
			"AS_ODSTSniperLeft",
			"AS_ODSTSniperRight",
			"AS_SmallLeft",
			"AS_SmallRight",
			"AP_AR",
			"AP_BR",
			"AP_Canteen",
			"AP_GL",
			"AP_Knife",
			"AP_MGThigh",
			"AP_AR",
			"AP_Pack",
			"AP_Pistol",
			"AP_Rounds",
			"AP_SG",
			"AP_SMG",
			"AP_Sniper",
			"AP_Thigh",
			"AP_Frag",
			"AP_Smoke",
			"APO_AR",
			"APO_BR",
			"APO_Knife",
			"APO_SMG",
			"APO_Sniper",
			"CustomKit_Scorch"
		};
		hiddenSelectionsTextures[]= // the actual textures being used by this if it were put in game and worn or placed on the ground
		{
			"OPTRE_UNSC_Units\Army\data\vest_co.paa", // this is the hard-body armour texture, including marine shoulderpads
			"optre_unsc_units\army\data\armor_co.paa", // this is the softbody portion of the texture, the gel layer under the hard parts, basically. oh, also the shoulder "straps" on the back of the vest.
			"optre_unsc_units\army\data\legs_co.paa", // legs. both use the same texture.
			"optre_unsc_units\army\data\ghillie_woodland_co.paa", // ghille net, if you're into that sort of thing.
			"optre_unsc_units\army\data\odst_armor_co.paa" // all ODST portions of the armour, assuming those are being used. if not, you can leave this field empty or not even include the "texturePath" segment in the config
		};
		class ItemInfo: VestItem // a lot of the above is redefined down here, with a few key differences.
		{
			vestType="Rebreather"; // this one, for example. i'm pretty sure this is the only default arma vestType. i could be wrong, though.
			uniformModel="\OPTRE_UNSC_Units\Army\armor.p3d"; // once again, model the vest uses lol
			containerClass="Supply160"; // capacity of the vest. just change the three-digit number after the "Supply" bit to change capacity
			mass=80; // weight, in arma mass units (0.05 kg or 0.1lb)
			modelSides[]={6}; // no idea. sometimes you need this to be defined as it is here. above my paygrade, honestly lol
			hiddenSelections[]= // be sure that you define these ones as the same as you did before, otherwise your shit won't show up. delete or put a // before them if you want them to show up.
			{
				"camo",
				"camo2",
				"camo3",
				"camo4",
				"camo5",
				"A_Base",
				"A_ChestArmor",
				"A_Ghillie",
				"A_KneesLeft",
				"A_KneesRight",
				"A_KneesMarLeft",
				"A_KneesMarRight",
				"A_ODST",
				"A_ShinArmorLeft",
				"A_ShinArmorRight",
				"A_TacPad",
				"A_ThighArmorLeft",
				"A_ThighArmorRight",
				"AS_BaseLeft",
				"AS_BaseRight",
				"AS_LargeLeft",
				"AS_LargeRight",
				"AS_MediumLeft",
				"AS_MediumRight",
				"AS_ODSTCQBLeft",
				"AS_ODSTCQBRight",
				"AS_ODSTLeft",
				"AS_ODSTRight",
				"AS_ODSTSniperLeft",
				"AS_ODSTSniperRight",
				"AS_SmallLeft",
				"AS_SmallRight",
				"AP_AR",
				"AP_BR",
				"AP_Canteen",
				"AP_GL",
				"AP_Knife",
				"AP_MGThigh",
				"AP_AR",
				"AP_Pack",
				"AP_Pistol",
				"AP_Rounds",
				"AP_SG",
				"AP_SMG",
				"AP_Sniper",
				"AP_Thigh",
				"AP_Frag",
				"AP_Smoke",
				"APO_AR",
				"APO_BR",
				"APO_Knife",
				"APO_SMG",
				"APO_Sniper",
				"CustomKit_Scorch"
			};
			hiddenSelectionsTextures[]= // textures again. should be the same as the one above.
			{
				"OPTRE_UNSC_Units\Army\data\vest_co.paa",
				"optre_unsc_units\army\data\armor_co.paa",
				"optre_unsc_units\army\data\legs_co.paa",
				"optre_unsc_units\army\data\ghillie_woodland_co.paa",
				"optre_unsc_units\army\data\odst_armor_co.paa"
			};
			class HitpointsProtectionInfo // damage protection values. small changes are almost unnoticeable. look into the hitpoints documentation on the community wiki before you change these values.
			{
				class Neck
				{
					hitpointName="HitNeck";
					armor=30;
					passThrough=0.1;
				};
				class Legs
				{
					hitpointName="HitLegs";
					armor=30;
					passThrough=0.1;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=30;
					passThrough=0.1;
				};
				class Hands
				{
					hitpointName="HitHands";
					armor=30;
					passThrough=0.1;
				};
				class Chest
				{
					hitpointName="HitChest";
					armor=30;
					passThrough=0.1;
				};
				class Diaphragm
				{
					hitpointName="HitDiaphragm";
					armor=30;
					passThrough=0.1;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=30;
					passThrough=0.1;
				};
				class Pelvis
				{
					hitpointName="HitPelvis";
					armor=30;
					passThrough=0.1;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=30;
					passThrough=0.1;
				};
			};
		};
	}; // okay, that one was a doozy. luckily, we don't have to redefine *every single thing* again because inheritance is really cool and works in your favour if you need a bunch of items with the same values.
	// it's good practice to make a scope=0; or scope=1; item as a "base" for other items, if you need multiple with the same or similar values, but different textures, names, the likes. every time you inherit from something, only things that you directly redefine get changed, hence it being called "inheritance"

	class my_cool_vest: my_default_vest // depending on how many things we want to change, we might need to redefine certain things just to be safe.
	{
		displayName="My Cool Vest!"; // some common practices with names for items include [Unit] before the name, because it moves your item to the top of the arsenal in that category. or at least, closer to the top. eg. [82ndSOC] is what ours have.
		author="me!";
		scope=2;
		scopeArsenal=2; // i'm not putting scopeCurator in because it doesn't matter as much for worn items. unless you want zeus to be able to slap them down from the spawn menu
		hiddenSelectionsTextures[]=
		{
			"", // this is where i would put the filepath to the texture of my hard plate armour
			"", // same but for the soft armour bits
			"", // once again, but for the leg
			"", // fuck ghilles lol
			"" // odst bits, if i'm using them
		};
	}; // unless i want this vest to use different hiddenSelections, i won't be putting itemInfo in here at all. the idea is that this would act exactly the same as my_default_vest but have specific textures, maybe for all the riflemen or something

	class my_odst_helmet_base: OPTRE_UNSC_CH252D_Helmet // now onto the odst helmet. this one has a bit more explanation required as it has more absolute definitions going on in some respects.
	{
		scope=0;
		author="me!";
		ace_hearing_protection=1; // if you use ace hearing, set this to 1 on any closed or ear-covering helmet. you will thank me later.
		ace_hearing_lowerVolume=0.60000002; // this slightly decreases apparent volume of sounds, similar to earplugs, though less noticeable. OPTRE has a trend of using oddly specific decimal values that have little to no rhyme or reason.
		displayName="-";
		hiddenSelectionsTextures[]= // textures to be used by the helmet and its visor.
		{
			"82nd_Armor_New\data\armors\Helmets\V_CH252D_DEF_CO", // helmet itself
			"82nd_Armor_New\data\armors\Helmets\V_CH252D_DEF_V_CO" // helmet's visor
		};
		hiddenSelectionsMaterials[]= // this one is for rvmat files. if you don't know what an rvmat is, look at the code for the helmet this inherits from in OPTRE_UNSC_Units and use those rvmat paths. never leave these empty
		{
			"82nd_Armor_New\data\armors\Helmets\V_CH252D.rvmat", // rvmat for the helmet
			"82nd_Armor_New\data\armors\Helmets\V_CH252D_V.rvmat" // rvmat for the visor
		};
		CBRN_protection=1; // is it a gas mask? 1 = yes, 0 = no.
		class ItemInfo: HeadgearItem // you may have noticed a lot of double-defines going on. the reason i suggested making "base" items that only exist to be inherited from is exactly this. it's a pain to define shit over and over again if it's going to be the same most of the time.
		{
			mass=30;
			uniformModel="OPTRE_UNSC_Units\Army\odst_helmet";
			picture="\OPTRE_UNSC_Units\Army\icons\odst_helmet";
			hiddenSelections[]= // these aren't defined outside of the ItemInfo here, mostly because if you have them in here, they're ignored on the outside sometimes. never hurts to double-define though.
			{
				"camo",
				"camo2"
			};
			hiddenSelectionsTextures[]=
			{
				"82nd_Armor_New\data\armors\Helmets\V_CH252D_DEF_CO",
				"82nd_Armor_New\data\armors\Helmets\V_CH252D_DEF_V_CO"
			};
			hiddenSelectionsMaterials[]=
			{
				"82nd_Armor_New\data\armors\Helmets\V_CH252D.rvmat",
				"82nd_Armor_New\data\armors\Helmets\V_CH252D_V.rvmat"
			};
			class HitpointsProtectionInfo // damage protection values. see the comment on my_default_vest if you forgot what i said about these lol
			{
				class Face
				{
					armor=25;
					hitpointName="HitFace";
					passThrough=0.1;
				};
				class Head
				{
					armor=25;
					hitPointName="HitHead";
					passThrough=0.1;
				};
				class Neck
				{
					armor=20;
					hitpointName="HitNeck";
					passThrough=0.1;
				};
			};
		};
		allowedFacewear[]={}; // do you want to restrict what facewear can be worn with this helmet or helmets that inherit from this? leave it empty if no.
	};
	class my_odst_helmet_base_dp: OPTRE_UNSC_CH252D_Helmet_dp // this helmet is the depolarized version of the one above. the only difference is that the visor can be transparent on this one.
	{
		scope=0;
		author="Mesa";
		ace_hearing_protection=1;
		ace_hearing_lowerVolume=0.1; // some people do a lil immersion thing and decrease sound dampening on the depolarized helmets. pretty neat, if you ask me.
		displayName="-";
		hiddenSelections[]=
		{
			"camo",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"82nd_Armor_New\data\armors\Helmets\V_CH252D_DEF_CO",
			"82nd_Armor_New\data\armors\Helmets\V_CH252D_CLR_V_CA" // difference #1 between this one and the normal one. different visor for starters
		};
		hiddenSelectionsMaterials[]=
		{
			"82nd_Armor_New\data\armors\Helmets\V_CH252D.rvmat",
			""																							// difference #2 is no rvmat for the visor.... interesting choice, Article 2. doesn't actually matter in this case, just neat is all.
		};
		CBRN_protection=1; // still a gas mask lol
		class ItemInfo: HeadgearItem
		{
			mass=30;
			uniformModel="OPTRE_UNSC_Units\Army\odst_helmet_dp";
			picture="\OPTRE_UNSC_Units\Army\icons\odst_helmet";
			hiddenSelections[]=
			{
				"camo",
				"camo2"
			};
			hiddenSelectionsTextures[]=
			{
				"82nd_Armor_New\data\armors\Helmets\V_CH252D_DEF_CO",
				"82nd_Armor_New\data\armors\Helmets\V_CH252D_CLR_V_CA"
			};
			hiddenSelectionsMaterials[]=
			{
				"82nd_Armor_New\data\armors\Helmets\V_CH252D.rvmat",
				""
			};
			class HitpointsProtectionInfo
			{
				class Face
				{
					armor=25;
					hitpointName="HitFace";
					passThrough=0.1;
				};
				class Head
				{
					armor=25;
					hitPointName="HitHead";
					passThrough=0.1;
				};
				class Neck
				{
					armor=20;
					hitpointName="HitNeck";
					passThrough=0.1;
				};
			};
		};
		allowedFacewear[]={};
	};
	class my_odst_helmet: 82nd_CH252D_Helmet_Base
	{
		scope=2;
		scopeArsenal=2;
		author="me!";
		displayName="my cool helmet!";
		hiddenSelectionsTextures[]=
		{
			"", // filepath to your texture for the helmet.
			"" // same but for the visor
		};
	};
	class my_odst_helmet_dp: 82nd_CH252D_Helmet_Base_dp // the reason this one has _dp at the end is because of how the "depolarize visor"/HUD system works. with this helmet, it needs a duplicate helmet but with a different visor texture and _dp at the end of the classname so it can work its magic. just be sure to inherit from the right places!!!
	{
		scope=2;
		scopeArsenal=1; // we hide this one to preserve the magic of how the depolarize function works
		author="me!";
		displayName="my cool helmet! (dp)";
		hiddenSelectionsTextures[]=
		{
			"", // should be the same as the above's texture.
			"" // this should be the difference. make sure this one is transparent. you can grab that from OPTRE_UNSC_Units, either by filepath or just by copying the texture into your own mod. either should work.
		};
	};
	
}; // simple retextures usually end up having more time spent on the actual texture itself than config. unless you're rewriting an entire mod from the ground up, but already have the textures on hand. would not recommend 0/10

// ##############
// ## Closing Notes!!! ###
// ##############
//		Hey there! I didn't want this to be too fucking wide, so not everything is as detailed as I would have liked.
//		That being said, had I known most of this stuff sooner in my modding career, I might have had less sleepless nights debugging lmfao
//		Patience is a virtue with modding, and experience comes with time. Don't be afraid to ask questions of Thomas or any other A2S devs, 
//		though don't expect all of them to be versed in the whole of OPTRE's massive codebase. It's a big fucking mod lol.
//		Feel free to reach out at any point to me via DMs or ping in a server we share, I'm always happy to help a budding config gremlin!
//		Pro Tip: ORGANIZE YOUR FOLDERS!!! It will save you a lot of time in the long run, even if it's annoying as fuck at first.
// 	I personally like to have all my M52A vests in one place, helmets in another, though that's personal preference.
// 	Don't let people judge you for being new to config. It's a massive fucking beast, and even the A2S devs started somewhere.