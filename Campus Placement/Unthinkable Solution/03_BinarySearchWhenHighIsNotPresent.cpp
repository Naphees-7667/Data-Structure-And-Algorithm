✅ Optimized Approach : Exponential Search + Binary Search
🔹 Step 1 : Exponential Expansion
    Start small and double the range until you go past the key :

    low = 0 high = 1

    while (arr[high] < key){
        low = high
        high *= 2
    } 
    This helps you find a small window[low, high] such that the key must lie inside it if present.

🔹 Step 2 : Binary Search in[low, high] Now,
    do standard binary search between that range : 
    while (low <= high)
    {
        mid = Math.floor((low + high) / 2) 
        if (arr[mid] == = key) return mid 
        else if (arr[mid] < key) low = mid + 1 
        else high = mid - 1
    }
    return -1