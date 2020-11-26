/*
 * parser.h
 *
 *  Created on: 14 nov. 2020
 *      Author: nico
 */

#ifndef PARSER_H_
#define PARSER_H_
int parser_ClienteFromText(FILE* pFile , LinkedList* pArrayListCliente);
int parser_AfichesFromText(FILE* pFile , LinkedList* pArrayListAfiches);
//int parser_ClienteFromBinary(FILE* pFile , LinkedList* pArrayListCliente);


#endif /* PARSER_H_ */
