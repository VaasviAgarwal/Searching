#include <iostream>
using namespace std;

class binarsearcharray
{
    private:
    int lo;
    int hi;
    int mid;
    int *a;
    int x;
    int size;
    public:
    binarsearcharray(int *arr, int s, int el)
    {
         lo =0;
	     size = s;
         hi = size-1;
         a = arr;
         x = el;
    }
    int search()
    {
	int i;
        if (a[0]<a[size-1])
        {
            for (i=0;i<size-1;i++)
            {
                if(a[i]>a[i+1])
                {
                    return -2;
                }
            }
            while (hi-lo>1)
            {
                int mid = (hi-lo)/2;
                if(a[mid]<x)
                {
                    lo = mid+1;
                }
                else
                {
                    hi = mid;
                }
            }
            if(a[lo]==x)
            {
                return lo;
            }
        }
        else
        {
            for (i=0;i<size-1;i++)
            {
                if(a[i]<a[i+1])
                {
                    return -2;
                }
            }
            while (hi-lo>1)
            {
                int mid = (hi-lo)/2;
                if(a[mid]>x)
                {
                    lo = mid+1;
                }
                else
                {
                    hi = mid;
                }
            }
            if(a[hi]==x)
            {
                return hi;
            }  
        }
        return -1;
    }
};

int main()
{
    cout << "Enter the number of elements in the array : ";
    int s;
    cin >> s;
    cout << "Enter the elements of the array in sorted format" << endl;
    int a[s];
    int i;
    for (i=0;i<s;i++)
    {
        cin >> a[i];
    }
    cout <<"Enter the number to be searched : ";
    int x;
    cin >> x; 
    binarsearcharray ob(a,s,x);
    int ans = ob.search();
    if(ans==-1)
    {
        cout <<"Number not present in the array "<< endl;
    }
    else if (ans==-2)
    {
        cout <<"Array is not sorted therefore binary search cannot be performed"<<endl;
    }
    else
    {
        cout << "Number present at  position " << ans+1 << " in the array" << endl;
    }
    return 0;
}
