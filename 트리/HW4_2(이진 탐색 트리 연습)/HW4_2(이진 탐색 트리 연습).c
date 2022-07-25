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
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (root == NULL) return new_node(key);
	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (key < root->key)
		root->left = insert_node(root->left, key);
	else
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
	if (key < root->key)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	else if (key > root->key)
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
		root->key = temp->key;
		// 중외 순회시 후계 노드를 삭제한다. 
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

void preorder(TreeNode* root) // p271 코드 복사 
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
	while (current->right != NULL) // 맨 왼쪽 단말 노드를 찾으러 내려감 
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
				printf("삽입할 key값 입력:");
				scanf_s("%d", &key);
				root = insert_node(root, key);
				while (getchar() != '\n');
				break;
			case 'd' :
				printf("삭제할 key값 입력:");
				scanf_s("%d", &key);
				root = delete_node(root, key);
				while (getchar() != '\n');
				break;
			case 's':
				printf("탐색할 key값 입력:");
				scanf_s("%d", &key);
				if (search(root, key) != NULL)
					printf("있음\n");
				else
					printf("없음\n");
				while (getchar() != '\n');
				break;
			case 'p':
				preorder(root);
				printf("\n");
				while (getchar() != '\n');
				break;
			case 'h':
				printf("트리의 높이는 %d\n", get_height(root));
				while (getchar() != '\n');
				break;
			case 'c':
				printf("노드의 개수는 %d\n", count(root));
				while (getchar() != '\n');
				break;
			case 'm':
				printf("가장 큰 값은 %d\n", get_maximum(root)->key);
				while (getchar() != '\n');
				break;
			case 'n':
				printf("가장 작은 값은 %d\n", min_value_node(root)->key);
				while (getchar() != '\n');
				break;
			case 'q':
				break;
			default:
				printf("잘못된 입력입니다.");
		}
	} while (f != 'q');
}