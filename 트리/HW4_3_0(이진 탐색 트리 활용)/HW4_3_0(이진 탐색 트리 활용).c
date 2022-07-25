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
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (root == NULL) return new_node(key);
	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (key.id < root->data.id)
		root->left = insert_node(root->left, key);
	else if (key.id > root->data.id)
		root->right = insert_node(root->right, key);
	// 변경된 루트 포인터를 반환한다. 
	return root;
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL) // 맨 왼쪽 단말 노드를 찾으러 내려감 
		current = current->left;
	return current;
}

TreeNode* delete_node(TreeNode* root, int key)
{
	TreeNode* temp;
	if (root == NULL) return root;

	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (key < root->data.id)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	else if (key > root->data.id)
		root->right = delete_node(root->right, key);
	// 키가 루트와 같으면 이 노드를 삭제하면 됨
	else {
		// 첫 번째나 두 번째 경우
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
		// 세 번째 경우
		temp = min_value_node(root->right);
		// 중외 순회시 후계 노드를 복사한다. 
		root->data = temp->data;
		// 중외 순회시 후계 노드를 삭제한다. 
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

void inorder(TreeNode* root) // p271 코드 복사 
{
	if (root) {
		inorder(root->left);
		printf("-----------------------------------------\n");
		printf("학번: %d\n이름: %s\n전화번호: %s\n학과: %s\n", root->data.id, root->data.name, root->data.tel, root->data.dept);
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
	while (current->right != NULL) // 맨 왼쪽 단말 노드를 찾으러 내려감 
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
			printf("학번 입력:");
			scanf_s("%d", &id);
			printf("이름 입력:");
			scanf_s("%s", name, sizeof(name));
			printf("전화번호 입력:");
			scanf_s("%s", tel, sizeof(tel));
			printf("학과 입력:");
			scanf_s("%s", dept, sizeof(dept));
			key.id = id;
			strcpy_s(key.name, MAX_STRING, name);
			strcpy_s(key.tel, MAX_STRING, tel);
			strcpy_s(key.dept, MAX_STRING, dept);
			root = insert_node(root, key);
			while (getchar() != '\n');
			break;
		case 'd':
			printf("삭제할 학번 입력:");
			scanf_s("%d", &id);
			root = delete_node(root, id);
			while (getchar() != '\n');
			break;
		case 's':
			printf("탐색할 학번 입력:");
			scanf_s("%d", &id);
			s = search(root, id);
			if (s != NULL) {
				printf("-----------------------------------------\n");
				printf("학번: %d\n이름: %s\n전화번호: %s\n학과: %s\n", s->data.id, s->data.name, s->data.tel, s->data.dept);
			}
			else
				printf("id가 %d인 학생은 없읍니다.\n", id);
			while (getchar() != '\n');
			break;
		case 'p':
			printf("학생 정보 학번 순 출력\n");
			inorder(root);
			printf("\n");
			while (getchar() != '\n');
			break;
		case 'c':
			printf("현재 저장된 학생의 총 수는 %d\n", count(root));
			while (getchar() != '\n');
			break;
		case 'q':
			break;
		default:
			printf("잘못된 입력입니다.");
		}
	} while (f != 'q');
}