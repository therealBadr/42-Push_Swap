# Push Swap Documentation

This project implements a sorting algorithm for a stack of integers using two stacks (`stack_a` and `stack_b`) and a set of predefined operations. The goal is to sort the integers in `stack_a` in ascending order using the fewest possible operations.

---

## File Structure

### `push_swap.c`
This file contains the main logic for the program.

#### Functions:
- **`int main(int argc, char **argv)`**:
  - The entry point of the program.
  - Calls the parsing function to process all arguments.
  - Returns an error if there is an issue during parsing.
  - Checks if `stack_a` is empty, contains duplicates, or is already sorted.
  - Initiates the sorting process by calling the `sorting_cases` function.

- **`static void sorting_cases(t_list **stack_a, t_list **stack_b)`**:
  - Determines the appropriate sorting algorithm based on the size of `stack_a`.
  - Calls the relevant sorting function (e.g., `big_sort` for stacks larger than 5).

---

### `parsing.c`
This file handles input validation and stack initialization.

#### Functions:
- **`int is_sorted(t_list *stack_a)`**:
  - Checks if `stack_a` is already sorted in ascending order.

- **`void clear_result(char **result)`**:
  - Frees the memory allocated for the 2D array created during parsing.

- **`int check_duplicate(t_list *stack_a)`**:
  - Checks for duplicate numbers in `stack_a`.

- **`int check_num(char *str)`**:
  - Validates if a string represents a valid integer.

- **`int parsing(char *str, t_list **stack_a)`**:
  - Splits the input arguments into a 2D array.
  - Calls `check_num` to validate each number.
  - Adds valid numbers to `stack_a`.

---

### `sort.c`
This file contains the core sorting logic for the stacks.

#### Functions:
- **`void big_sort(t_list **stack_a, t_list **stack_b)`**:
  - Sorts stacks with more than 5 elements.
  - Uses `get_my_range` to determine the working range for sorting.
  - Calls `assign_index` to assign indexes to elements based on their sorted order.
  - Calls `push_to_b` and `push_to_a` to perform the sorting.

- **`void push_to_b(t_list **stack_a, t_list **stack_b, int min, int max)`**:
  - Pushes elements from `stack_a` to `stack_b` based on their indexes.
  - If an element is within the range `[min, max]`, it is pushed to `stack_b`.
  - If an element is greater than `max`, it is rotated to the bottom of `stack_a`.
  - If an element is less than `min`, it is pushed to `stack_b` and rotated.

- **`void push_to_a(t_list **stack_a, t_list **stack_b)`**:
  - Pushes elements from `stack_b` back to `stack_a` in sorted order.
  - Uses `get_max_pos` to find the position of the maximum element in `stack_b`.
  - Rotates `stack_b` to bring the maximum element to the top, then pushes it to `stack_a`.

- **`int get_max_pos(t_list *stack)`**:
  - Finds the position of the maximum element in the stack.

- **`int get_my_range(int size)`**:
  - Determines the working range for the sorting algorithm based on the size of the stack.

---

### `indexing.c`
This file handles indexing and cloning of the stack for sorting purposes.

#### Functions:
- **`t_list *lst_clone(t_list *lst)`**:
  - Creates a clone of the given linked list `lst`.
  - Returns the cloned list.

- **`void del_max(t_list **clone, t_list *max)`**:
  - Deletes the node with the maximum value from the cloned list.
  - Updates the cloned list to remove the maximum node.

- **`void find_max(t_list **original, t_list **clone, int *index)`**:
  - Finds the maximum value in the cloned list.
  - Assigns the corresponding index to the node in the original list.
  - Deletes the maximum node from the cloned list.

- **`void assign_index(t_list **lst)`**:
  - Assigns indexes to all nodes in the list based on their sorted order.
  - Uses a cloned list to determine the order of elements.

---

### `lst_utils.c`
This file contains utility functions for working with linked lists.

#### Functions:
- **`t_list *new_node(int data)`**:
  - Creates a new node with the given `data`.
  - Returns the newly created node.

- **`void add_back(t_list **lst, t_list *new)`**:
  - Adds a new node to the end of the linked list.

- **`int size_lst(t_list *lst)`**:
  - Returns the number of nodes in the linked list.

- **`void clear_all(t_list **lst)`**:
  - Frees all nodes in the linked list and sets the list to `NULL`.

- **`t_list *last_lst(t_list *lst)`**:
  - Returns the last node in the linked list.

---

