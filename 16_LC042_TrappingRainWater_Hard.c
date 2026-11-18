int trap(int* height, int heightSize)
{
    int leftMax[20000], rightMax[20000];
    int i, water = 0;

    leftMax[0] = height[0];

    for(i = 1; i < heightSize; i++)
    {
        if(height[i] > leftMax[i-1])
            leftMax[i] = height[i];
        else
            leftMax[i] = leftMax[i-1];
    }

    rightMax[heightSize-1] = height[heightSize-1];

    for(i = heightSize-2; i >= 0; i--)
    {
        if(height[i] > rightMax[i+1])
            rightMax[i] = height[i];
        else
            rightMax[i] = rightMax[i+1];
    }

    for(i = 0; i < heightSize; i++)
    {
        if(leftMax[i] < rightMax[i])
            water = water + leftMax[i] - height[i];
        else
            water = water + rightMax[i] - height[i];
    }

    return water;
}
