This version of D2Multi generates d2m.dll used by D2Bot # with kolbot in the 1.13d branch.

D2Multi was originally written as a multi-window loader. It was adapted as a loader for d2bot # with kolbot, d2m.dll, with features added to modify window loading behavior and with cache fix.

d2m.dll is used for 1.13d versions of D2bot # with kolbot
since 1.14d with unified game.exe removing the individual game dlls, d2bs has absorbed the d2m features.

One reason d2m.dll was used to begin with is because d2bot # would load d2 in a suspended state and inject d2m.dll to do some early initialization. After resuming, the game would load the other libraries normally at which point d2bs can be injected. For 1.14d this is not required because the game launches with all libraries loaded.

Credits:
Original author of D2Multi is ejact@blizzhackers
D2Multi is also based on another d2 loader by gnarmock@blizzhackers
D2Multi also came with an injector based on work by sheppard@blizzhackers