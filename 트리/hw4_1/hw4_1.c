#include <stdio.h> 
#include <stdlib.h> 
#include <memory.h>

#define TRUE 1 
#define FALSE 0 
#define MAX_TREE_SIZE 20 

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode n1 = { 15, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 15, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

TreeNode m1 = { 15, NULL, NULL };
TreeNode m2 = { 4, &n1, NULL };
TreeNode m3 = { 16, NULL, NULL };
TreeNode m7 = { 28, NULL, NULL }; // �߰� 
TreeNode m4 = { 25, NULL, &m7 }; // ���� 
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode* root2 = &m6;

//p281 Quiz 01 
int get_nonleaf_count(TreeNode* t) {
	int count = 0;

	if (t != NULL) {
		if (t->left == NULL && t->right == NULL)
			return 0;
		else
			count = 1 + get_nonleaf_count(t->left) + get_nonleaf_count(t->right);
	}

	return count;
}

//p281 Quiz 02 
int equal(TreeNode* t1, TreeNode* t2) {
	if (t1 != NULL && t2 != NULL) {
		if (t1->data != t2->data)
			return 0;
		else {
			equal(t1->left, t2->left);
			equal(t1->right, t2->right);
		}
	}
	return 1;

	/* ������ �ڵ�
	if(t1 == NULL && t2 == NULL)
		return 1;
	else if(t1 == NULL || t2 == NULL)
		return 0;
	else if (t1->data != t2->data)
		return 0;
	else 
		return equal(t1->left, t2->left) && equal(t1->right, t2->right);
	*/
}

//p308 #25 
int get_oneleaf_count(TreeNode* node) {
	int count = 0;

	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			return 0;
		else if (node->left != NULL && node->right == NULL) {
			count = 1 + get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
		}
		else if (node->right != NULL && node->left == NULL) {
			count = 1 + get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
		}
		else
			count = get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
	}

	return count;
}

//p308 #26 
int get_twoleaf_count(TreeNode* node) {
	int count = 0;

	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			return 0;
		else if (node->left != NULL && node->right != NULL) {
			count = 1 + get_twoleaf_count(node->left) + get_twoleaf_count(node->right);
		}
		else
			count = get_twoleaf_count(node->left) + get_twoleaf_count(node->right);
	}

	return count;
}

//p308 #27 
int get_max(TreeNode* node) {
	int n1 = 0, n2 = 0, n3 = 0;

	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			return node->data;

		n1 = get_max(node->left);
		n1 = get_max(node->right);
		n3 = node->data;

		if (n1 > n2 && n1 > n3)
			return n1;
		else if (n2 > n3)
			return n2;
		else
			return n3;
	}

	/* ������ �ڵ�
	if(node)
		return max(max(node->data, get_max(node->left)), get_max(node->right));
	else
		return INT_MIN;
	*/
}

int get_min(TreeNode* node) {
	int n1 = 0, n2 = 0, n3 = 0;

	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			return node->data;

		n1 = get_max(node->left);
		n1 = get_max(node->right);
		n3 = node->data;

		if (n1 < n2 && n1 < n3)
			return n1;
		else if (n2 < n3)
			return n2;
		else
			return n3;
	}
}

//p308 #30 
void node_increase(TreeNode* node) { 
	if (node != NULL) {
		node->data++;
		node_increase(node->left);
		node_increase(node->right);
	}
	else
		return;
}

void preorder(TreeNode* root) // p271 �ڵ� ���� 
{
	if (root) {
		printf("%d ", root->data); 
		preorder(root->left); 
		preorder(root->right); 
	}
}

TreeNode* copy(TreeNode* node) {
	TreeNode* temp = malloc(sizeof(struct TreeNode));

	if (node == NULL) {
		return NULL;
	}
	else {
		temp->left = copy(node->left);
		temp->right = copy(node->right);
		temp->data = node->data;

		return temp;
	}

	/* ������ �ڵ�
	if (node != NULL) {
		temp->data = node->data;
		temp->left = node->left;
		temp->right = node->right;
		copy(node->left);
		copy(node->right);
	}		

	return temp;
	*/
}

int main(void)
{
	TreeNode* result[MAX_TREE_SIZE];
	TreeNode* clone;
	int i, num;

	printf("��)\n");
	printf("Ʈ�� root �� ��ܸ������ ������ %d.\n", get_nonleaf_count(root));
	printf("Ʈ�� root2 �� ��ܸ������ ������ %d.\n", get_nonleaf_count(root2));

	printf("Ʈ�� root �� �ڽ��� �ϳ��� �ִ� ����� ������ %d.\n", get_oneleaf_count(root));
	printf("Ʈ�� root2 �� �ڽ��� �ϳ��� �ִ� ����� ������ %d.\n", get_oneleaf_count(root2));
	
	printf("Ʈ�� root �� �ڽ��� ���� �ִ� ����� ������ %d.\n", get_twoleaf_count(root));
	printf("Ʈ�� root2 �� �ڽ��� ���� �ִ� ����� ������ %d.\n", get_twoleaf_count(root2));

	printf("Ʈ�� root ���� ���� ū ���� %d.\n", get_max(root));
	printf("Ʈ�� root2 ���� ���� ū ���� %d.\n", get_max(root2));
	printf("Ʈ�� root ���� ���� ���� ���� %d.\n", get_min(root));
	printf("Ʈ�� root2 ���� ���� ���� ���� %d.\n", get_min(root2));

	/*
	printf("\n ��)\n");
	num = search(root, 15, result);
	for (i = 0; i < num; i++)
		printf("(0x%p, %d), ", result[i], result[i]->data);
	printf("\n");
	*/

	printf("\n ��)\n");
	preorder(root);
	node_increase(root);
	printf("\n");
	preorder(root);
	printf("\n");

	printf("%s\n", equal(root, root) ? "����" : "�ٸ���");
	printf("%s\n", equal(root2, root2) ? "����" : "�ٸ���");
	printf("%s\n", equal(root, root2) ? "����" : "�ٸ���");

	printf("\n ��)\n");
	clone = copy(root);
	preorder(root);
	printf("\n");
	preorder(clone);
	printf("\n");
}