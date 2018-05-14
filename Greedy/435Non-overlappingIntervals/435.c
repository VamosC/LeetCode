/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
void quickSort(struct Interval* intervals, int left, int right);
void median(struct Interval* intervals, int left, int right);
void swap(struct Interval* p, struct Interval* q);
int eraseOverlapIntervals(struct Interval* intervals, int intervalsSize) {
	int num;
	int m, n;
	num = 0;
	quickSort(intervals, 0, intervalsSize-1);
	m = 0;
	while(m < intervalsSize)
	{
		num++;
		n = m+1;
		while(n < intervalsSize && intervals[n].start < intervals[m].end)
		{
			n++;
		}
		m = n;
	}
	return intervalsSize - num;
}

void quickSort(struct Interval* intervals, int left, int right)
{
	int i, j;
	if(left < right)
	{
		i = left;
		j = right - 1;
		median(intervals, left, right);
		while(i < j)
		{
			while(intervals[++i].end < intervals[right-1].end);
			while(intervals[--j].end > intervals[right-1].end);
			if(i < j)
			{
				swap(&intervals[i], &intervals[j]);
			}
			else
			{
				break;
			}
		}
		swap(&intervals[i], &intervals[right-1]);
		quickSort(intervals, left, i-1);
		quickSort(intervals, i+1, right);
	}
}

void median(struct Interval* intervals, int left, int right)
{
	int center;
	center = (left+right)/2;
	if(intervals[left].end > intervals[center].end)
	{
		swap(&intervals[left], &intervals[center]);
	}
	if(intervals[left].end > intervals[right].end)
	{
		swap(&intervals[left], &intervals[right]);
	}
	if(intervals[center].end > intervals[right].end)
	{
		swap(&intervals[center], &intervals[right]);
	}
	swap(&intervals[center], &intervals[right-1]);
}

void swap(struct Interval* p, struct Interval* q)
{
	int temp1, temp2;
	temp1 = p->start;
	temp2 = p->end;
	p->start = q->start;
	p->end = q->end;
	q->start = temp1;
	q->end = temp2;
}