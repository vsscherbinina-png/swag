def bubble_sort(arr):
    """
    Реализация пузырьковой сортировки на Python
    
    Args:
        arr: список чисел для сортировки
    
    Returns:
        отсортированный список
    """
    n = len(arr)
    for i in range(n - 1):
        has_swap = False
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                # Обмен элементов
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                has_swap = True
        # Если обменов не было, массив уже отсортирован
        if not has_swap:
            break
    return arr


# Демонстрация работы
if __name__ == "__main__":
    data = [5, 2, 8, 1, 9]
    sorted_data = bubble_sort(data.copy())
    print("Результат пузырьковой сортировки:", sorted_data)



def insertion_sort(collection):
    for current_index in range(1, len(collection)):
        current_value = collection[current_index]
        position = current_index
        
        while position > 0 and collection[position - 1] > current_value:
            collection[position] = collection[position - 1]
            position -= 1
        
        collection[position] = current_value
    return collection

# Пример использования
if __name__ == "__main__":
    sample_data = [12, 11, 13, 5, 6]
    sorted_data = insertion_sort(sample_data.copy())
    print(f"Результат сортировки вставками: {sorted_data}")




def merge_sort(collection):
    if len(collection) <= 1:
        return collection
    
    middle = len(collection) // 2
    left_part = merge_sort(collection[:middle])
    right_part = merge_sort(collection[middle:])
    
    return merge(left_part, right_part)

def merge(left, right):
    result = []
    left_index = right_index = 0
    
    while left_index < len(left) and right_index < len(right):
        if left[left_index] <= right[right_index]:
            result.append(left[left_index])
            left_index += 1
        else:
            result.append(right[right_index])
            right_index += 1
    
    result.extend(left[left_index:])
    result.extend(right[right_index:])
    return result

# Пример использования
if __name__ == "__main__":
    sample_data = [38, 27, 43, 3, 9, 82, 10]
    sorted_data = merge_sort(sample_data.copy())
    print(f"Результат сортировки слиянием: {sorted_data}")





def quick_sort(collection):
    if len(collection) <= 1:
        return collection
    
    pivot = collection[len(collection) // 2]
    left = [x for x in collection if x < pivot]
    middle = [x for x in collection if x == pivot]
    right = [x for x in collection if x > pivot]
    
    return quick_sort(left) + middle + quick_sort(right)

# Пример использования
if __name__ == "__main__":
    sample_data = [10, 7, 8, 9, 1, 5]
    sorted_data = quick_sort(sample_data.copy())
    print(f"Результат быстрой сортировки: {sorted_data}")






def binary_search(collection, target):
    left, right = 0, len(collection) - 1
    
    while left <= right:
        middle = (left + right) // 2
        if collection[middle] == target:
            return middle
        elif collection[middle] < target:
            left = middle + 1
        else:
            right = middle - 1
    
    return -1

# Пример использования
if __name__ == "__main__":
    sorted_data = [2, 3, 4, 10, 40]
    target_value = 10
    result_index = binary_search(sorted_data, target_value)
    
    if result_index != -1:
        print(f"Элемент {target_value} найден на позиции {result_index}")
    else:
        print("Элемент не найден")






def interpolation_search(collection, target):
    low, high = 0, len(collection) - 1
    
    while low <= high and target >= collection[low] and target <= collection[high]:
        if low == high:
            if collection[low] == target:
                return low
            return -1
        
        pos = low + ((target - collection[low]) * (high - low)) // (collection[high] - collection[low])
        
        if collection[pos] == target:
            return pos
        elif collection[pos] < target:
            low = pos + 1
        else:
            high = pos - 1
    
    return -1

# Пример использования
if __name__ == "__main__":
    sorted_data = [10, 12, 13, 16, 18, 19, 20]
    target_value = 18
    result_index = interpolation_search(sorted_data, target_value)
    
    if result_index != -1:
        print(f"Элемент {target_value} найден на позиции {result_index}")
    else:
        print("Элемент не найден")




