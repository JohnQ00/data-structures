#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct hash_table h_table;
typedef struct element t_element;

h_table *create_hash_table(int size);
t_element* create_element(int key, int value);

void put(h_table *ht, int key, int element);
int get(h_table *ht, int key);

void print_hash_table(h_table *ht);

int main()
{
	int times; scanf("%d", &times);
	int i;
	for (i = 0; i < times; i++)
	{
		if (i > 0){printf("\n");}

		int adresses,elements;
		scanf("%d %d", &adresses,&elements);

		h_table *ht = create_hash_table(adresses);

		int j,elements2;
		for (j = 0; j < elements; ++j)
		{
			scanf("%d", &elements2);
			put(ht,elements2,elements2);
		}

		print_hash_table(ht);
	}

	return 0;
}

struct hash_table
{
	int size;
	t_element **table;
};

struct element
{
	int key;
	int value;
	t_element *next;
};

h_table *create_hash_table(int size)
{
	h_table *new_hash_table = (h_table*)malloc(1 * sizeof(h_table));
	int i;
	new_hash_table->table = (t_element**)malloc(size * sizeof(t_element));
	new_hash_table->size = size;
		for (i = 0; i < size; i++)
			new_hash_table->table[i] = NULL;

	return new_hash_table;
}

t_element *create_element(int key, int value)
{
	t_element *new_element = (t_element*)malloc(1 * sizeof(t_element));
	new_element->key = key;
	new_element->value = value;
	new_element->next = NULL;
	return new_element;
}

int hash_f(int key, int size)
{
	int h = key % size;
	if(h < 0){h = size + h;};
	return h;
}

void put(h_table *ht, int key, int value)
{
	t_element *new_element = create_element(key,value);

	int h = hash_f(key, ht->size);
	if (ht->table[h] == NULL)
	{
		ht->table[h] = new_element;
	}
	else
	{
		t_element *current = ht->table[h];
			while(current->next != NULL){current = current -> next;}
		current->next = new_element;
	}
}

void print_hash_table(h_table *ht)
{
	int i;
	for (i = 0; i < ht->size; ++i)
	{
		printf("%d -> ", i);
		t_element *current = ht->table[i];
			while(current != NULL)
			{
				printf("%d -> ", current->value);
				current = current->next;
			}printf("\\\n");
	}
}
