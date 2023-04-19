

DROP DATABASE IF EXISTS juego;
CREATE DATABASE juego;
USE juego;
CREATE TABLE jugador(
username VARCHAR(20) NOT NULL,
password VARCHAR(20) NOT NULL
)ENGINE= InnoDB;
CREATE TABLE partida(
ide INTEGER NOT NULL,
duracion INTEGER NOT NULL,
ganador TEXT NOT NULL
)ENGINE= InnoDB;
CREATE TABLE relacion(
jugador VARCHAR(20) NOT NULL,
ide_partida INTEGER NOT NULL,
partidas_ganadas INTEGER NOT NULL
)ENGINE= InnoDB;

INSERT INTO jugador VALUES("ElSardinilla","McManagan");
INSERT INTO jugador VALUES("DaniPedrosa","7Enanitos");
INSERT INTO jugador VALUES("PabloMontos","Altramuces");
