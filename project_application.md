
 Course: COEN 2220 - Programming 2
 Name: [Aida S.. Mendoza Gonzalez]
 Lab: Lab 11 - Recursion and Merge Sort
 Description: Project aplications information to fill up
 Due date: [3 de noviembre de 2026]
 
# Lab 11 - Project Application

## E1 - Original collection and borrowed pointers
Describe orders, view, and which array stores the actual records.

Answser: 
The orders array stores the actual OrderPreview records(OrderPreview orders[4];, line 24). The view array stores borrowed pointers (OrderPreview* view[MAX];, line 32 ) that reference selected orders in orders. The actual data remains in orders, while view only keeps their addresses for the temporary report.

## E2 - Implemented view and test
Describe the four dummy cases, the expected selected IDs, and the observed IDs.
Explain how you checked that original data and storage order were preserved.

answer:
The dummy cases were (Line 24-30):
OrderPreview orders[MAX] =
    {
        {10, "DELIVERY", "PENDING", "Engineering", 3},
        {11, "DELIVERY", "IN_PROGRESS", "Library", 2},
        {12, "DINE_IN", "PENDING", "StudentCenter", 4},
        {13, "DELIVERY", "COMPLETED", "Engineering", 1}
    }; 
The expected IDs:
10 and 11
because it has active DELIVERY on them.

The observed Ids:
10 and 11

The original data is saved in an array (order) and are preserved because I used a pointer variable (view).

## E3 - Sorting criterion and next integration step
State the three comparison rules and give a small example of their expected order.
Identify the remaining integration work, if any.

Answer:

The three comparison rules are:
Building in alphabetical order.
Priority in descending order within the same building.
Order ID in ascending order when there is a tie.

Example:
Order 15 - Engineering - Priority 3 
Order 10 - Engineering - Priority 2
Order 20 - Library - Priority 5

Expected order:
15, 10, 20

The remaining integration work is to adapt the merge sort so it can sort the pointers stored in the view according to these three rules.

## E4 - Lab evidence
Source file: delivery_view_practice.cpp
Test output: delivery_view_output.txt
Explain how this practice prepares the project's temporary report.

This helps us to use it as a reference to have an idea to what to do or expect. Maybe how we can implement it on a class and do better hud or more user friendly.