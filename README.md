# OPTRE_AuxMod_References


# ====== DISCLAIMER ======


This repo is intended to be a place for members of the OPTRE community to acquire textures and information regarding retexturing OPTRE assets for use in unit mods.

Operation: TREBUCHET can be found here: https://steamcommunity.com/sharedfiles/filedetails/?id=769440155&searchtext=operation+trebuchet

This repository is not guaranteed to be every single retexturable thing in Operation: TREBUCHET, though all files contained within this repo *are* guaranteed to be of retexturable assets.

There will be some notes contained within directories of this repo to help end users locate config within the main branch of OPTRE, as to implement these textures effectively. Any questions that are not answered by any notes contained in this repo should be directed to the Article 2 Studios discord server: https://discord.gg/xaK2y32KSu

These filepaths may not directly represent the actual filepaths in any portion of the OPTRE mod, they are intended to be more human-legible and as such are formatted accordingly. Any instances where direction to the "home" location of a given file is necessary, will be in the given folder's README.md.


# ====== INFORMATIONAL ======


Arma 3 handles mods almost identically to how it handles first-party DLC. As such, your files must be formatted to some particular standards:

Images: 8-bit integer precision, with a resolution of some power of 2 (1024x1024, 2048x2048, up to a maximum of 4096x4096)

Images must also be in a format known as PAA or PAC, which can be freely converted to or from via TexView2, a tool included with Arma 3 Tools on Steam. PAC files have mostly fallen out of fashion, and as such should be considered a deprecated file format.


Directories must be contained in a proprietary form of file compression known as PBO, converting to and from which can be done via a program included in a folder in this repository "PBOManager"


PBOs must be named after the `class cfgPatches` name in the config contained within their primary directory. (If your PBO is called Steve_Chestplates then your `class cfgPatches` name should be `class Steve_Chestplates`)

Most mods are organized into multiple PBO files as to both optimize and organize their contents. OPTRE, for example, has separate locations for weapons, vehicles, spartans, marine armor, and terrains to name a few.

Some, though not all, modders choose to binarize their config files within their PBOs not to obfuscate but to optimize performance of their mod. While not strictly necessary, if any given config file is in excess of around 10,000 lines, it is certainly recommended.

