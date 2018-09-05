/*********************************************************************
** Author: Jaspal Bainiwal
** Date: 04/23/2018
** Description: This is the implementation of the dynamic array for ADT's
stack and bag.
** Input: data to be stored ini dynamic array.
** Output: Operation types to be performed on bags and stacks.
************************************************************************/

#include <assert.h>
#include <stdlib.h>
#include "header.h"

struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};

void initDynArr(DynArr *v, int capacity)
{
	assert(capacity > 0);
	assert(v != 0);
	v->data = (TYPE *)malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = capacity;
}

DynArr* newDynArr(int cap)
{
	assert(cap > 0);
	DynArr *r = (DynArr *)malloc(sizeof(DynArr));
	assert(r != 0);
	initDynArr(r, cap);
	return r;
}

void freeDynArr(DynArr *v)
{
	if (v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

void deleteDynArr(DynArr *v)
{
	freeDynArr(v);
	free(v);
}

void _dynArrSetCapacity(DynArr *v, int newCap)
{
	TYPE* _data;
	int _size;

	_data = v->data;
	_size = v->size;
	/*using the innitDynArray with new cap so I dont have to rewrite the malloc code.*/
	initDynArr(v, newCap);

	for (int index = 0; index <_size; index++)
	{
		v->data[index] = _data[index];
	}
	/*freeing memory just like from worksheet 14*/
	v->size = _size;
	free(_data);

	/* FIXME: You will write this function */

}

int sizeDynArr(DynArr *v)
{
	return v->size;
}

void addDynArr(DynArr *v, TYPE val)
{
	/*using the code that was from worksheet 14's pdf. */
	/*if statement to see if the capacity has been reached if so call setcap function to update capacity.*/
	if (v->size >= v->capacity)
	{
		_dynArrSetCapacity(v, v->capacity * 2);
	}

	v->data[v->size] = val;
	v->size++;
	/* FIXME: You will write this function */
}

TYPE getDynArr(DynArr *v, int pos)
{
	/* FIXME: You will write this function */

	/* FIXME: you must change this return value */
	/*super simple fix just since all this function does is "get" data at certain pos in array*/
	return v->data[pos];
}
void putDynArr(DynArr *v, int pos, TYPE val)
{
	/* FIXME: You will write this function */
	v->data[pos] = val;
}

void swapDynArr(DynArr *v, int i, int  j)
{
	/* FIXME: You will write this function */
	TYPE holder;
	holder = v->data[i];

	v->data[i] = v->data[j];
	v->data[j] = holder;
}

void removeAtDynArr(DynArr *v, int idx)
{
	/* FIXME: You will write this function */
	assert((idx >= 0) && (idx < (v->size)));
	while (idx < v->size)
	{
		v->data[idx] = v->data[idx + 1];
		idx++;
	}
	v->size--;
}

int isEmptyDynArr(DynArr *v)
{
	/* FIXME: You will write this function */

	/* FIXME:  You will change this return value*/
	/*very simple stack operation that returns 1 for true and 0 for false*/
	if (v->size == 0)
	{
		/*That means its true the stack is empty*/
		return 1;
	}
	else
	{
		return 0;
	}
}
void pushDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */
	/*pushing is very simple it adds to the top of the stack which will be the last element in dyn array*/
	assert(v != 0);
	addDynArr(v, val);

}

TYPE topDynArr(DynArr *v)
{
	/* FIXME: You will write this function */

	/* FIXME: You will change this return value*/
	/*returning the top would mean getting the last element index -1*/

	assert(v != 0);
	assert(!isEmptyDynArr(v));
	TYPE _size;
	_size = v->size;
	return v->data[_size - 1];
}

void popDynArr(DynArr *v)
{
	/* FIXME: You will write this function */
	assert(v != 0);
	assert(!isEmptyDynArr(v));
	TYPE _size = v->size;
	removeAtDynArr(v, _size - 1);

}

int containsDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */

	/* FIXME:  You will change this return value */
	/*with bags the array is unsorted since data is just put in anywhere.
	That is why i need to iterate through entire dynarray.*/
	for (int index = 0; index < v->size; index++)
	{
		if (v->data[index] == val)
		{
			return 1;
		}
	}
	return 0;
}

void removeDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */
	/*removing from bag is bit tricky, but with the removeAtdynArray function it makes it
	easier. First I loop to find the data to remove. Then once I find it I call the remove
	function and return to the caller. */

	for (int index = 0; index < v->size; index++)
	{
		if (EQ(val, v->data[index]))
		{
			removeAtDynArr(v, index);
			return;
		}
	}
}
