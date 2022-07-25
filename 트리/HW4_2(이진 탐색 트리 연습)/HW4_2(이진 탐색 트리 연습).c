#include <stdio.h>
#include <stdlib.h> 
#include <memory.h> 
#define TRUE 1 
#define FALSE 0 

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* root, int key)
{
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
	if (root == NULL) return new_node(key);
	// �׷��� ������ ��ȯ������ Ʈ���� ��������. 
	if (key < root->key)
		root->left = insert_node(root->left, key);
	else
		root->right = insert_node(root->right, key);
	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return root;
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL) // �� ���� �ܸ� ��带 ã���� ������ 
		current = current->left;
	return current;
}

TreeNode* delete_node(TreeNode* root, int key)
{
	TreeNode* temp;
	if (root == NULL) return root;

	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (key < root->key)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	// Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
	else {
		// ù ��°�� �� ��° ���
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// �� ��° ���
		temp = min_value_node(root->right);
		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�. 
		root->key = temp->key;
		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�. 
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL) return NULL;

	if (key == node->key) return node;

	if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

void preorder(TreeNode* root) // p271 �ڵ� ���� 
{
	if (root) {
		printf("%d ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

int get_height(TreeNode* node)
{
	int height = 0;

	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));

	return height;
}

int count(TreeNode* t) {
	int c = 0;

	if (t != NULL) {
		if (t->left == NULL && t->right == NULL)
			return 1;
		else
			c = 1 + count(t->left) + count(t->right);
	}

	return c;
}

TreeNode* get_maximum(TreeNode* node)
{
	TreeNode* current = node;
	while (current->right != NULL) // �� ���� �ܸ� ��带 ã���� ������ 
		current = current->right;
	return current;
}

int main(void) {
	TreeNode* root = NULL;
	char f;
	int key;

	do {
		printf("Enter i<nsert>, d<elete>, s<earch>, p<rint>, h<eight>, c<ount>, m<ax>, n<min>, q<uit>:");
		scanf_s("%c", &f, sizeof(f));

		switch (f) {
			case 'i' :
				printf("������ key�� �Է�:");
				scanf_s("%d", &key);
				root = insert_node(root, key);
				while (getchar() != '\n');
				break;
			case 'd' :
				printf("������ key�� �Է�:");
				scanf_s("%d", &key);
				root = delete_node(root, key);
				while (getchar() != '\n');
				break;
			case 's':
				printf("Ž���� key�� �Է�:");
				scanf_s("%d", &key);
				if (search(root, key) != NULL)
					printf("����\n");
				else
					printf("����\n");
				while (getchar() != '\n');
				break;
			case 'p':
				preorder(root);
				printf("\n");
				while (getchar() != '\n');
				break;
			case 'h':
				printf("Ʈ���� ���̴� %d\n", get_height(root));
				while (getchar() != '\n');
				break;
			case 'c':
				printf("����� ������ %d\n", count(root));
				while (getchar() != '\n');
				break;
			case 'm':
				printf("���� ū ���� %d\n", get_maximum(root)->key);
				while (getchar() != '\n');
				break;
			case 'n':
				printf("���� ���� ���� %d\n", min_value_node(root)->key);
				while (getchar() != '\n');
				break;
			case 'q':
				break;
			default:
				printf("�߸��� �Է��Դϴ�.");
		}
	} while (f != 'q');
}