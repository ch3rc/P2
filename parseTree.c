//==========================================================
//Date:		Apr 24,2020
//Author:	Cody Hawkins
//Class:	CS4280
//Project:	P2
//File:		parseTree.c
//==========================================================
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "node.h"

//added memory to word tokens and things started working
struct Node *newNode(char* token)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->token = (char*)malloc(sizeof(token) + 1);
	strcpy(temp->token, token);
	temp->size = 0;
	temp->child = NULL;
	return temp;
}

//increase the size of the parent node for each additional child that attaches
//to it
void getNode(struct Node* parent, struct Node* child)
{
	struct Node *temp = newNode("");
	temp->child = (struct Node *)malloc(sizeof(struct Node));
	parent->child = (struct Node*)realloc(parent->child, sizeof(struct Node) * (parent->size + 1));
	temp->child = child;
	parent->child[parent->size] = *(temp->child);
	parent->size++;
}

//print out all parents and children
void preOrder(struct Node *root, int level)
{
	if(root->token != NULL)
	{
		printf("%*c%s\n", level * 2, ' ', root->token);
		
		int i = 0;
		while(i < root->size)
		{
			preOrder(&root->child[i], level + 1);
			i++;
		}
	}
}
