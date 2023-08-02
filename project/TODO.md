### kichkiro ------------------------------------------------------------------>

- [v] leaks parser
- [ ] aggiungere struttura mlx a t_scene
- [ ] gestire errori in caso di scena invalida
- [v] spostare definizione lista in minirt.h
- [v] ri-aggiungere libft e minilbx (puoi aggiungerle come submodule per evitare ridondanze di file)
- [v] file sorgente, header e Makefile
- [v] il Makefile di miniRT deve compilare le librerie direttamente
- [v] Invalid read of size 1 at: get_value (get_value.c:21)

- [ ] PARSING
	- [ ] Una scena per essere valida deve contenere: Ambient light, Camera, Luce, massimo 1 oggetto per tipo, altrimenti stampa "Error\n"
	- [ ] ambient->rgb contiene 0,0,0 indipendentemenre da cosa c'e' scritto nella scena

- [ ] aggiungere proprietà a oggetti della scena is_selected, per selezionare un oggetto e modificare le sue proprietà
- [ ] aggiungere un campo a t_scene per tenere traccia del tipo di oggetto (proporrei un enum, piu' elegante, ma non so se e' conforme alla norma, anche una macro o una stringa puo' andare bene) e rendere l'id univoco per ogni singolo oggetto
- [ ] Aggiungere funzione find_object_by_id(il nome puo' anhe cambiare) per ritornare un puntatore ad un oggetto nella scena in base all'id
- [ ] Aggiungere funzione find_object_by_type(il nome puo' anhe cambiare) per ritornare un array di puntatori agli oggetti nella scena in base al tipo (da definire prima di implementare)


### anvannin ------------------------------------------------------------------>

[x] libreria vector
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

[ ] window
- [x] init
- [x] destroy
- [x] suggerimenti
- [ ] update

[ ] raycasting
- [x] disgna il cielo

[ ] rendering
- [x] disegna una sfera
- [ ] asse x e y della sfera devono risulare in uno shift di pixel nella scena dal centro dello schermo [WIN_WIDHT/2, WIN_HEIGHT/2], non dai pixel [0, 0]

### altro --------------------------------------------------------------------->
