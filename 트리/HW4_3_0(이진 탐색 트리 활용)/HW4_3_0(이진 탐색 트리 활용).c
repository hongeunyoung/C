#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define MAX_STRING 100 

typedef struct {
	int id;
	char name[MAX_STRING];
	char tel[MAX_STRING];
	char dept[MAX_STRING];
} element;

typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* new_node(element item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* root, element key)
{
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
	if (root == NULL) return new_node(key);
	// �׷��� ������ ��ȯ������ Ʈ���� ��������. 
	if (key.id < root->data.id)
		root->left = insert_node(root->left, key);
	else if (key.id > root->data.id)
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
	if (key < root->data.id)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	else if (key > root->data.id)
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
		root->data = temp->data;
		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�. 
		root->right = delete_node(root->right, temp->data.id);
	}
	return root;
}

TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL) return NULL;

	if (key == node->data.id) return node;

	if (key < node->data.id)
		return search(node->left, key);
	else
		return search(node->right, key);
}

void inorder(TreeNode* root) // p271 �ڵ� ���� 
{
	if (root) {
		inorder(root->left);
		printf("-----------------------------------------\n");
		printf("�й�: %d\n�̸�: %s\n��ȭ��ȣ: %s\n�а�: %s\n", root->data.id, root->data.name, root->data.tel, root->data.dept);
		inorder(root->right);
	}
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
	TreeNode* s = NULL;
	element key;
	char f;
	int id;
	char name[MAX_STRING];
	char tel[MAX_STRING];
	char dept[MAX_STRING];

	do {
		printf("Enter i<nsert>, d<elete>, s<earch>, p<rint>, c<ount>, q<uit>:");
		scanf_s("%c", &f, sizeof(f));

		switch (f) {
		case 'i':
			name[0] = '\n';
			tel[0] = '\n';
			dept[0] = '\n';
			printf("�й� �Է�:");
			scanf_s("%d", &id);
			printf("�̸� �Է�:");
			scanf_s("%s", name, sizeof(name));
			printf("��ȭ��ȣ �Է�:");
			scanf_s("%s", tel, sizeof(tel));
			printf("�а� �Է�:");
			scanf_s("%s", dept, sizeof(dept));
			key.id = id;
			strcpy_s(key.name, MAX_STRING, name);
			strcpy_s(key.tel, MAX_STRING, tel);
			strcpy_s(key.dept, MAX_STRING, dept);
			root = insert_node(root, key);
			while (getchar() != '\n');
			break;
		case 'd':
			printf("������ �й� �Է�:");
			scanf_s("%d", &id);
			root = delete_node(root, id);
			while (getchar() != '\n');
			break;
		case 's':
			printf("Ž���� �й� �Է�:");
			scanf_s("%d", &id);
			s = search(root, id);
			if (s != NULL) {
				printf("-----------------------------------------\n");
				printf("�й�: %d\n�̸�: %s\n��ȭ��ȣ: %s\n�а�: %s\n", s->data.id, s->data.name, s->data.tel, s->data.dept);
			}
			else
				printf("id�� %d�� �л��� �����ϴ�.\n", id);
			while (getchar() != '\n');
			break;
		case 'p':
			printf("�л� ���� �й� �� ���\n");
			inorder(root);
			printf("\n");
			while (getchar() != '\n');
			break;
		case 'c':
			printf("���� ����� �л��� �� ���� %d\n", count(root));
			while (getchar() != '\n');
			break;
		case 'q':
			break;
		default:
			printf("�߸��� �Է��Դϴ�.");
		}
	} while (f != 'q');
}