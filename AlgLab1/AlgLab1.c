
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>


struct tnode
{
	int data;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *root1 = NULL; *root2 = NULL;

int* A;

int main() {
	return 0;
}

int tsize(struct tnode* t) {	
	if (t = NULL) {
		return 0;
	}
	else {
		return 1 + tsize(t->left) + tsize(t->right);
	}
}

int theight(struct tnode* t) {
	if (t == NULL) {
		return 0;
	}
	else {
		return 1 + max(theight(t->left), theight(t->right));
	}
}

int tmiddleh(struct tnode* t, int l) {
	if (t == NULL) {
		return 0;
	}
	else {
		return l + tmiddleh(t->left, l + 1) + tmiddleh(t->right, l + 1);
	}
}

int csumm(struct tnode* t) {
	if (t == NULL) {
		return 0;
	}
	else {
		return t->data + csumm(t->left) + csumm(t->right);
	}
}

void ltr(struct tnode* t) {
	if (t != NULL) {
		ltr(t->left);
		printf("%d", t->data, " ");
		ltr(t->right);
	}
}

void search(struct tnode* t, int x) {
	if (t != NULL) {
		if (t->data < x) {
			search(t->right, x);
		}
		else if (t->data > x) {
			search(t->left, x);
		}
		else {
			printf("Вершина найдена.");
		}
	}
	else {
		printf("Вершина не найдена");
	}
}
struct tnode* isdp(int l, int r) {
	if (l > r) return NULL;
	else {
		int m = (l + r) / 2;
		struct tnode* t;
		t->data = A[m];
		t->left = isdp(l, m - 1);
		t->right = isdp(m + 1, r);
		return t;
	}
}
void sdp(struct tnode** t, int d) {
	if ((*t) == NULL) {
		(*t) = (struct tnode*)malloc(sizeof(struct tnode));
		(*t)->data = d;
		(*t)->left = (*t)->right = NULL;
	}
	else if ((*t)->data < d) {
		sdp(&((*t)->right), d);
	}
	else if ((*t)->data > d) {
		sdp(&((*t)->left), d);
	}
}

/*Вызов sdp:
for(i = 0; i < n; i++)
	{
		AddTree(&root, mass[i]);
	}*/