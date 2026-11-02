/*
 * Course: COEN 2220 - Programming 2
 * Name: [Aida S. Mendoza Gonzalez]
 * Lab: Lab 11 - Recursion and Merge Sort
 * Description: Practice - sort a temporary view without changing original tasks
 * Due date: [2 noviembre de 2026]
 */

#include <iostream>
#include <string>
using namespace std;

struct RepairTask
{
    string taskId;     // Preserve the identity of the original task.
    int daysUntilDue;  // Smaller values must appear first in the report.
    int minutesNeeded; // Break equal-deadline ties with smaller durations first.
};

bool comesBeforeOrEqual(const RepairTask *left, const RepairTask *right);
void mergeTaskView(RepairTask *view[], RepairTask *temporary[],
                   int first, int middle, int last);
void mergeSortView(RepairTask *view[], RepairTask *temporary[], int first, int last);
void displayOriginal(const RepairTask tasks[], int count);
void displayView(RepairTask *view[], int count);

int main()
{
    const int TASK_COUNT = 8;
    RepairTask tasks[TASK_COUNT] =
    {
        {"RT-101", 3, 30}, {"RT-102", 1, 20},
        {"RT-103", 2, 15}, {"RT-104", 1, 10},
        {"RT-105", 2, 15}, {"RT-106", 3, 10},
        {"RT-107", 1, 20}, {"RT-108", 2, 5}
    };
    RepairTask *view[TASK_COUNT];      // Borrow addresses of existing tasks.
    RepairTask *temporary[TASK_COUNT]; // Hold addresses while merging the view.
    for (int index = 0; index < TASK_COUNT; index++)
    {
        view[index] = &tasks[index]; // Preserve arrival order in the initial view.
    }

    cout << boolalpha;
    cout << "Original arrival order:" << endl;
    displayOriginal(tasks, TASK_COUNT);

    // ===== Resolve these TODOs now (Part C) =====
    // TODO (Part C): Activate the C test block after completing the comparator.
    
    cout << "Earlier deadline first: "
         << comesBeforeOrEqual(&tasks[1], &tasks[0]) << endl;
    cout << "Shorter duration within same deadline: "
         << comesBeforeOrEqual(&tasks[3], &tasks[1]) << endl;
    cout << "Exact tie keeps left: "
         << comesBeforeOrEqual(&tasks[2], &tasks[4]) << endl;
    cout << "Later deadline first: "
         << comesBeforeOrEqual(&tasks[0], &tasks[1]) << endl;
    

    // ===== Resolve these TODOs later (Part D) =====
    // TODO (Part D): Call mergeSortView for the complete logical range.
    // TODO (Part D): Display the sorted view with a descriptive heading.
    // TODO (Part D): Display tasks again to prove that arrival order did not change.
    mergeSortView(view, temporary, 0, TASK_COUNT - 1);
    cout << endl << "Sorted view:" << endl;
    displayView(view, TASK_COUNT);
    cout << endl << "Original arrival order remains:" << endl;
    displayOriginal(tasks, TASK_COUNT);


    return 0;
}

bool comesBeforeOrEqual(const RepairTask *left, const RepairTask *right)
{
    // ===== Resolve this TODO now (Part C) ===== Done
    // TODO (Part C): Implement the specified two-field order, including exact ties.

    if (left->daysUntilDue < right->daysUntilDue)
    {
        return true;
    }

    if (left->daysUntilDue > right->daysUntilDue)
    {
        return false;
    }

    if (left->minutesNeeded < right->minutesNeeded)
    {
        return true;
    }

    if (left->minutesNeeded > right->minutesNeeded)
    {
        return false;
    }

    return true; // Exact tie: keep the left task first.
}

// ===== Resolve these TODOs later (Part D) =====
void mergeSortView(RepairTask *view[], RepairTask *temporary[], int first, int last)
{
    // TODO (Part D): Implement recursive merge sort using inclusive indices.
    if (first >= last)
    {
        return; // Base case: 0 or 1 element.
    }

    int middle = (first + last) / 2;

    mergeSortView(view, temporary, first, middle);
    mergeSortView(view, temporary, middle + 1, last);

    mergeTaskView(view, temporary, first, middle, last);
}

void mergeTaskView(RepairTask *view[], RepairTask *temporary[],
                   int first, int middle, int last)
{
    // TODO (Part D): Merge two sorted segments using comesBeforeOrEqual.
    // TODO (Part D): Preserve pending pointers and copy the merged segment back.
    int left = first;
    int right = middle + 1;
    int index = first;

    while (left <= middle && right <= last)
    {
        if (comesBeforeOrEqual(view[left], view[right]))
        {
            temporary[index] = view[left];
            left++;
        }
        else
        {
            temporary[index] = view[right];
            right++;
        }

        index++;
    }

    while (left <= middle)
    {
        temporary[index] = view[left];
        left++;
        index++;
    }

    while (right <= last)
    {
        temporary[index] = view[right];
        right++;
        index++;
    }

    for (int i = first; i <= last; i++)
    {
        view[i] = temporary[i];
    }
}

void displayOriginal(const RepairTask tasks[], int count)
{
    for (int index = 0; index < count; index++)
    {
        cout << "Task: " << tasks[index].taskId
             << " | Days until due: " << tasks[index].daysUntilDue
             << " | Minutes: " << tasks[index].minutesNeeded << endl;
    }
}

void displayView(RepairTask *view[], int count)
{
    for (int index = 0; index < count; index++)
    {
        cout << "Task: " << view[index]->taskId
             << " | Days until due: " << view[index]->daysUntilDue
             << " | Minutes: " << view[index]->minutesNeeded << endl;
    }
}

/*
 * Analysis Answers
 *
 * C5 - Two-field decision
 * Explain the result for RT-103 compared with RT-108. Which field decides it?
 * 
 * Answer:
 *  RT-103 and RT-108 have val 2 (daysUntilDue ), so the first field does not determine the order. 
 * The comparison is decided by minutesNeeded: RT-108 needs 5 minutes, while RT-103 requires 15 minutes.
 * So RT-108 comes first because it has smaller minutesNeeded value than RT-103(the minutesNeeded decides if its fisrt or not).
 *
 * D1 - Recursive ranges
 * Show first, last, middle, and the base-case evaluations along the first branch
 * starting at 0..7. Identify where execution resumes after the call for 0..0.
 * 
 * Answer:
 *  Starting at 0..7: middle=3, then 0..3; middle=1, then 0..1; middle=0, then 0..0. 
 * The range 0..0 is a base case because first >= last. After 0..0 
 * returns, execution resumes in the call for 0..1 and continues with 1..1.
 *
 * 
 * D2 - Stable ties
 * Identify both pairs of tasks that tie in the two sort fields. Explain how the
 * comparator and the merge preserve their arrival order.
 * 
 * Answer:
 * The exact ties are RT-102 and RT-107 (1,20) and RT-103 and RT-105 (2,15). 
 * The comparator returns true on exact ties, and the merge takes the left element first,
 * preserving the original arival order.
 *
 *
 * D3 - Time, space, and original data
 * Give the sorting time and auxiliary-space order of this pointer-array version.
 * Compare with the linked-list sort in Part B and explain why the original task
 * storage order is preserved here but the node order changes in Part B.
 * 
 * Answer:
 * The sorting time order is O(n log n) and the auxiliary-space order is O(n) because of the temporary pointer array. 
 * Part B only the pointers in view are rearranged, so the original tasks array remains unchanged;
 * the node links are rearranged, changing the list order.
 *
 */