# TODO

## Subject ------------------------------------------------------------------->

### Mandatory

- [?] You must use the miniLibX. Either the version that is available on the 
	  operating system, or from its sources. If you choose to work with the 
	  sources, you will need to apply the same rules for your libft as those 
	  written above in Common Instructions part.

	  ***NOTE: Do we need to norminetting the mlx?***

- [v] The management of your window must remain fluid: switching to another 
	  window, minimization, etc..

- [v] When you change the resolution of the window, the content of the window 
	  must remain unchanged and be adjusted accordingly.

- [ ] You need at least these 3 simple geometric objects: plane, sphere, 
	  cylinder.

- [v] If applicable, all possible intersections and the inside of the object 
	  must be handled correctly.

- [ ] Your program must be able to resize the object’s unique properties: 
	  diameter for a sphere and the width and height for a cylinder.

- [ ] Your program must be able to apply translation and rotation 
      transformation to objects, lights and cameras (except for spheres and 
	  lights that cannot be rotated).

- [v] Light management: spot brightness, hard shadows, ambiance lighting 
	  (objects are Never completely in the dark). You must implement Ambient 
	  and diffuse lighting.

- [v] The program displays the image in window and respect the following rules:
	- [v] Pressing ESC must close the window and quit the program cleanly.
	- [v] Clicking on the red cross on the window’s frame must close the window
		  and quit the program cleanly.
	- [v] The use of images of the minilibX is strongly recommended.
- [v] Your program must take as a first argument a scene description file with 
	  the .rt extension.
	- [v] Each type of element can be separated by one or more line break(s).
	- [v] Each type of information from an element can be separated by one or 
		  more space(s).
	- [v] Each type of element can be set in any order in the file.
	- [v] Elements which are defined by a capital letter can only be declared 
		  once in the scene.

### Bonus

- [ ] Add specular reflection to have a full Phong reflection model.

- [ ] Color disruption: checkerboard.

- [ ] Colored and multi-spot lights.

- [ ] One other 2nd degree object: Cone, Hyperboloid, Paraboloid..

- [ ] Handle bump map textures


## kichkiro ------------------------------------------------------------------>

- [v] leaks parser
- [v] gestire errori in caso di scena invalida
- [v] spostare definizione lista in minirt.h
- [v] ri-aggiungere libft e minilbx (puoi aggiungerle come submodule per 
		evitare ridondanze di file)
- [v] file sorgente, header e Makefile
- [v] il Makefile di miniRT deve compilare le librerie direttamente
- [v] Invalid read of size 1 at: get_value (get_value.c:21)

- [ ] PARSING
	- [ ] Una scena per essere valida deve contenere: Ambient light, Camera, 
		  Luce, massimo 1 oggetto per tipo, altrimenti stampa "Error\n"
	- [v] i colori degli oggetti sono invertiti, [255,0,255] dovrebbe essere 
		  viola, ma ritorna giallo (hai invertito il verde con il blu nel 
		  parsing)

- [v] aggiungere un campo a t_scene per tenere traccia del tipo di oggetto 
	  (proporrei un enum, piu' elegante, ma non so se e' conforme alla norma,
	  anche una macro o una stringa puo' andare bene) e rendere l'id univoco 
	  per ogni singolo oggetto.

## anvannin ------------------------------------------------------------------>

- [x] libreria vector
	- [x] Makefile
	- [x] spostare struttura t_coords in vector.h
	- [x] funzioni base
		- [x] distanza tra due punti
		- [x] addizione e sottrazione
		- [x] prodotto scalare
		- [x] prodotto incrociato
	- [x] funzioni avanzate
		- [x] modulo
		- [x] normalizzazione
		- [x] seno e coseno
		- [x] rotazioni

- [ ] window
	- [x] init
	- [x] destroy
	- [x] suggerimenti
	- [ ] update

- [ ] raycasting
	- [x] disegna il cielo

- [ ] rendering
	- [ ] disegna una sfera
		- [ ] il controllo sull'area deve essere fatta in base al centro della 
			  sfera, non dello schermo
	- [X] asse x e y della sfera devono risulare in uno shift di pixel nella 
		  scena dal centro dello schermo [WIN_WIDHT/2, WIN_HEIGHT/2], non dai 
		  pixel [0, 0]

## bugs ---------------------------------------------------------------------->

- [v] get_sphere non funziona (segmetation fault): `./project/src/sphere.c:15`
