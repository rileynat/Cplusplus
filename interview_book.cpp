#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

#include "external_lib.h" 

using namespace std;

struct Node {
	Node* parent;
	Node* left;
	Node* right;
	int value;
};


bool unique_char_string( string str ) {

  vector<bool> characters(128, false);
  for (string::iterator it = str.begin(); it < str.end(); it++ ) {
    cout << *it;
    if ( characters[*it] ) {
      return false;
    } else {
      characters[*it] = true;
    }
  }
  return true;

}

bool second_unique_char_string( string str ) {

  for (string::iterator it = str.begin(); it < str.end() - 1; it++ ) {
    cout << *it;
    //char current_char = *it;
    for (string::iterator iter = it + 1; iter < str.end(); iter++ ) {
      if (*iter == *it) {
	return false;
      }
    }
  }
  return true;

}

void char_array_rev( char* char_array ) {
  //cout << *char_array << endl;
  char* begin = char_array;
  if ( begin == '\0' ) { return; }
  char* end = begin + 1;
  if ( end == '\0' ) { return; }
  for ( char* it = begin + 1; *it != '\0'; it++ ) {
    //cout << *it << endl;
    end = it;
  }
  //cout << *begin << endl;
  //cout << *end << endl;
  
  while ( begin < end ) {
	cout << *begin << " " << *end << endl;
	char temp = *begin;
	*begin = *end;
	*end = temp;
    begin++;
    end--;
    cout << *(begin + 1) << " " << *(end - 1) << endl;
  }
}

string string_remove_duplicates( string str ) {
    
	for (string::iterator it = str.begin(); it < str.end(); it++ ) {
        //cout << *it;
        //char current_char = *it;
        for (string::iterator iter = it + 1; iter < str.end(); iter++ ) {
            if (*iter == *it) {
                str.erase(iter);
                cout << *iter << endl;
            }
        }
    }
    return str;
}

string replace_spaces( string str ) {
	
	for ( string::iterator it = str.begin(); it < str.end(); it++ ) {
		if ( *it == ' ' ) {
			str.replace(it, it + 1, "%20");
		}
	}
	return str;
	
}

void remove_duplicates_list( list<int> &myList ) {
    
	for ( auto it = myList.begin(); it != myList.end(); it++ ) {
        auto iter = it;
        if ( iter != myList.end() ){
            iter++;
            for ( ; iter != myList.end(); iter++ ) {
                
                if (*iter == *it ) {
                    myList.erase(iter);
                    //cout << *iter << endl;
                }
            }
        }
	}
}

list<int> add_int_lists( list<int> first, list<int> second ) {
	list<int> return_list;
	auto first_it = first.begin();
	auto second_it = second.begin();
	int sum = 0;
	while ( true ) {
		if ( first_it == first.end() ) {
			while ( second_it != second.end() ) {
				return_list.push_back(*second_it);
			}
			break;
		}
		if ( second_it == second.end() ) {
			while ( first_it != first.end() ) {
				return_list.push_back(*first_it);
			}
			break;
		}
		int temp = *first_it + *second_it + sum;
		return_list.push_back(temp % 10);
		sum = temp / 10;
		first_it++;
		second_it++; 
	}
	if ( sum != 0 ) {
		return_list.push_back(sum);
	}
	return return_list;
}


bool is_tree_balanced( Node* parent, int& count, int cur_depth ) {
	
	bool flag = true;
	
	if ( parent->left != NULL ) {
		cout << "going left from node " << parent->value << " to node " << parent->left->value;
		cout << " with count " << count << " and cur_depth " << cur_depth << endl;
		flag = is_tree_balanced(parent->left, count, cur_depth + 1);
		if ( flag == false ) {
			return flag;
		}
	}
	if ( parent->right != NULL ) {
		cout << "going right from node " << parent->value << " to node " << parent->right->value; 
		cout << " with count " << count << " and cur_depth " << cur_depth << endl;
		flag = is_tree_balanced(parent->right, count, cur_depth + 1);
		if ( flag == false ) {
			return flag;
		}
	}
	if ( parent->left == NULL || parent->right == NULL ) {
		if ( count == 0 ) {
			count = cur_depth;
			cout << "setting the count" << endl;
		} else {
			if ( cur_depth != count ) {
				flag = false;
				cout << " found uneven " << endl;
			} else {
				flag = true;
				cout << " found even " << endl;
			}
		}
	}
	
	return flag;
	
}


void print_tree( Node* node ) {
	if ( node->left != NULL ) {
		print_tree( node->left );
	}
	cout << node->value << " ";
	if ( node->right != NULL ) {
		print_tree( node->right );
	}
}

void destruct_tree( Node* node ) {
	if ( node->left != NULL ) {
		destruct_tree( node->left );
	}
	if ( node->right != NULL ) {
		destruct_tree( node->right );
	}
	cout << node->value << " ";
	delete node;
}

typedef vector<list<Node*> > Node_lists;

void create_lists( Node* node, Node_lists &lists, int cur_depth ) {
	if ( node->left != NULL ) {
		cout << "moving left" << endl;
		create_lists( node->left, lists, cur_depth + 1);
	}
	
	if ( lists.size() <= cur_depth ) {
		lists.resize(cur_depth );
	}
	cout << "adding " << node->value << " to list " << cur_depth - 1 << endl;
	lists[cur_depth - 1].push_back(node);
	
	if ( node->right != NULL ) {
		cout << "moving right " << endl;
		create_lists(node->right, lists, cur_depth + 1);
	}
} 

bool run_equal_checks( Node* root, Node* sub_root ) {

	cout << "run equal on " << root->value << " and " << sub_root->value << endl;
	if ( root != sub_root ) {
		return false;
	}
	if ( root->left != NULL ) {
		if ( sub_root->left == NULL ) {
			return false;
		}
		if ( !run_equal_checks( root->left, sub_root->left ) ) {
			return false;
		}
	}
	if ( root->right != NULL ) {
		if ( sub_root->right == NULL ) {
			return false;
		}
		if ( ! run_equal_checks( root->right, sub_root->right ) ) {
			return false;
		}
	}
	
	return true;
}

bool is_subtree ( Node* root, Node* sub_root ) {

	cout << root->value << endl;
	bool flag = false;
	if ( root->value == sub_root->value ) {
		return run_equal_checks( root, sub_root );
	}
	if ( root->left != NULL ) {
		flag = is_subtree( root->left, sub_root );
		if ( flag ) {
			return true;
		}
	}
	if ( root->right != NULL ) {
		flag = is_subtree( root->right, sub_root );
		if ( flag ) {
			return true;
		}
	}
	
	return false;
		
}


int main (int argc, char* argv[] ) {

//   string myString = argv[1];
//   //if ( second_unique_char_string(myString) ) {
//     //printf(" unique string of chars \n");
//   //} else {
//     //printf(" nonunique string of chars \n");
//   //}
// 
// 	myString = replace_spaces(myString);
// 	cout << myString << endl;	
	// string myString = "this is a string";
// 	myString = replace_spaces(myString);
// 	cout << myString << endl;
  //cout << "test" << endl;
  // char char_array[] = {'a','b','c','d','e','\0'};
//   char_array_rev(char_array);
//   for ( int i = 0; char_array[i] != '\0'; i++ ) {
//     cout << char_array[i];
//   }
//   cout << endl;
// 	int somethign = 5120959;
// 	cout << is_prime(somethign) << endl;
		
	// list<int> int_list;
// 	for ( int i = 0; i < 10; i++ ) {
// 		int_list.push_back(i);
// 	}
// 	for ( auto it = int_list.begin(); it != int_list.end(); it++ ) {
// 		cout << *it << endl;
// 	}
// 	remove_duplicates_list(int_list);


	// list<int> first_num;
// 	list<int> second_num;
// 
// 	first_num.push_back(6);
// 	first_num.push_back(4);
// 	first_num.push_back(3);
// 
// 	second_num.push_back(7);
// 	second_num.push_back(9);
// 	second_num.push_back(5);
// 
// 	list<int> added_list = add_int_lists( first_num, second_num );
// 
// 
// 	for ( auto it = added_list.begin(); it != added_list.end(); it++ ) {
// 		cout << *it << endl;
// 	}

// 	for ( int i = 0; i < 1000; i++ ) {
// 		cout << num_to_string_thou(i) << endl;
// 	}

	Node* top11 = new Node;
	top11->parent = NULL;
	top11->value = 11;
	top11->left= NULL;
	top11->right = NULL;
	
	Node* node3 = new Node;
	node3->value = 3;
	node3->parent = top11;
	top11->left = node3;
	node3->left= NULL;
	node3->right = NULL;
	
	Node* node16 = new Node;
	node16->value = 16;
	node16->parent = top11;
	top11->right = node16;
	node16->left = NULL;
	node16->right = NULL;
	
	Node* node1 = new Node;
	node1->value = 1;
	node1->parent = node3;
	node3->left = node1;
	node1->left= NULL;
	node1->right = NULL;
	
	Node* node6 = new Node;
	node6->value = 6;
	node6->parent = node3;
	node3->right = node6;
	node6->left= NULL;
	node6->right = NULL;
	
	Node* node13 = new Node;
	node13->value = 13;
	node13->parent = node16;
	node16->left = node13;
	node13->left = NULL;
	node13->right = NULL;
	
	Node *node18 = new Node;
	node18->value = 18;
	node18->parent = node16;
	node16->right = node18;
	node18->left = NULL;
	node18->right = NULL;
	
	Node *node2 = new Node;
	node2->value = 2;
	node2->parent = node1;
	node1->right = node2;
	node2->right = NULL;
	node2->left = NULL;
	
	Node *node0 = new Node;
	node0->value = 0;
	node0->parent = node1;
	node1->left = node0;
	node0->right = NULL;
	node0->left = NULL;
 	
	Node *node4 = new Node;
	node4->value = 4;
	node4->parent = node6;
	node6->left = node4;
	node4->left = NULL;
	node4->right = NULL;
	
	Node* node7 = new Node;
	node7->value = 7;
	node7->parent = node6;
	node6->right = node7;
	node7->left= NULL;
	node7->right = NULL;
	
	Node* node12 = new Node;
	node12->value = 12;
	node12->parent = node13;
	node13->left = node12;
	node12->left = NULL;
	node12->right = NULL;
	
	Node* node15 = new Node;
	node15->value = 15;
	node15->parent = node13;
	node13->right = node15;
	node15->left = NULL;
	node15->right = NULL;
	
	Node* node17 = new Node;
	node17->value = 17;
	node17->parent = node18;
	node18->left = node17;
	node17->left = NULL;
	node17->right = NULL;
	
	Node* node19 = new Node;
	node19->parent = node18;
	node19->value = 19;
	node18->right = node19;
	node19->left = NULL;
	node19->right = NULL; 
	
	int n = 0;
// 	print_tree(top11);
// 	cout << endl;
	
	//Node_lists lists;
	
	//create_lists(top11, lists, 1);
	
	bool flag = is_subtree( node3, node16 );
	
	destruct_tree(top11);
	
	cout << endl;
}
