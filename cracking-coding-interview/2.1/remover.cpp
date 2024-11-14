#include <stdio.h>

class node 
{
    private:
        int key;
        node* tail;
    public:
        node(int n_key)
        {
            key = n_key;
            tail = 0;
        }

        void set_tail(node* n_tail)
        {
            tail = n_tail;
        }

        node* get_tail()
        {
            return tail;
        }

        int get_key()
        {
            return key;
        }

};

class linked_list
{
    private:
        node* head;

    public:
        linked_list()
        {
            head = 0;
        }

        void insert_node(int n_key)
        {
            node* n_node = new node(n_key);
            if(head == 0)
            {
                head = n_node;
            }
            else
            {
                node* tmp = head;
                while(tmp->get_tail() != 0)
                {
                    tmp = tmp->get_tail();
                }
                tmp->set_tail(n_node);
            }
        }

        void print_nodes()
        {
            node* current = head;
            while(current != 0)
            {
                printf("%d\n", current->get_key());
                current = current->get_tail();
            }
        }

        void remove_duplicates()
        {
            node* current = head;
            node* search;
            node* prev_search;
            node* new_tail;

            int check_key;

            while(current->get_tail() != 0)
            {
                search = current->get_tail();
                prev_search = current;
                check_key = current->get_key();

                while(search != 0)
                {
                    if(search->get_key() == check_key)
                    {
                        printf("need to delete %d\n", search->get_key());
                        new_tail = search->get_tail();
                        prev_search->set_tail(new_tail);
                        delete search;
                        search = new_tail;
                    }
                    else
                    {
                        prev_search = search;
                        search = search->get_tail();
                    }
                }
                current = current->get_tail();
            }
        }
};



int main(int argc, char* argv[])
{
    linked_list* n_list = new linked_list();
    n_list->insert_node(15);
    n_list->insert_node(13);
    n_list->insert_node(12);
    n_list->insert_node(15);
    n_list->insert_node(15);
    n_list->insert_node(13);
    n_list->print_nodes();

    n_list->remove_duplicates();
    n_list->print_nodes();

    return 0;
}