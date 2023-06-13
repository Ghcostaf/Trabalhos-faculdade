import time

#funcao selection sort

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
      
#funcao bubble sort

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
              
#funcao insertion sort

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
      
# funcao merge sort

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1
# funcao quick sort
def quick_sort(arr, low, high):
    if low < high:
        pivot_index = partir(arr, low, high)
        quick_sort(arr, low, pivot_index - 1)
        quick_sort(arr, pivot_index + 1, high)
      
#A função partition é usada pelo algoritmo QuickSort para dividir o array em duas parte tendo em vista um pivô escolhido

def partir(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

# Função para medir o tempo de execução de um algoritmo
def measure_execution_time(algorithm, arr):
    start_time = time.time()
    algorithm(arr)
    end_time = time.time()
    execution_time = end_time - start_time
    return execution_time

# Função principal do programa
def main():
    arr = [64, 25, 12, 22, 11]
    algorithm = input("Escolha um algoritmo, Digite a letra que o acompanha para executar (SelectionSort(S), BubbleSort(B), InsertionSort(I), MergeSort(M), QuickSort(Q)): ")

    if algorithm == "s" or "S":
        execution_time = measure_execution_time(selection_sort, arr)
    elif algorithm == "b"or "B":
        execution_time = measure_execution_time(bubble_sort, arr)
    elif algorithm == "i"or "I":
        execution_time = measure_execution_time(insertion_sort, arr)
    elif algorithm == "m" or "M":
        execution_time = measure_execution_time(merge_sort, arr)
    elif algorithm == "q"or "Q":
        execution_time = measure_execution_time(lambda arr: quick_sort(arr, 0, len(arr) - 1), arr)
    else:
        print("Não temos essa opção.")
        return

    print("Array ordenado:", arr)
    print("Tempo de execução:", execution_time)

# Execução do programa
main()
