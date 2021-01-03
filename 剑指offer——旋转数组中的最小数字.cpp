/*
	剑指offer——旋转数组中的最小数字 
*/ 



int minArray(int* numbers, int numbersSize){
    if(numbers == NULL || numbersSize <= 0)
        return -1;

    int p = 0;
    int q = numbersSize -1;
    int mid = p;

    while(numbers[p] >= numbers[q])
    {
        
        if(q - p == 1)
        {
            mid = q;
            break;
        }

        mid = (p + q) / 2;

        if(numbers[p] == numbers[q] && numbers[mid] == numbers[p])
            return MinInOrder(numbers,p,q);

        if(numbers[mid] >= numbers[p])
        {
            p = mid;
        }
        else if(numbers[mid] < numbers[q])
        {
            q = mid;
        }
    } 

    return numbers[mid];
}
int MinInOrder(int *numbers, int p, int q)
{
    int result = numbers[p];
    for(int i = p+1; i <= q; ++i)
    {
        if(result > numbers[i])
            result = numbers[i];
    }

    return result;
}

