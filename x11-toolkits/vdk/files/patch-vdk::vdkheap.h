--- vdk/vdkheap.h.orig	Wed Nov 22 14:10:52 2000
+++ vdk/vdkheap.h	Thu Aug  5 19:16:36 2004
@@ -85,7 +85,7 @@
 VDKHeap<T>::VDKHeap(T* source, int size): VDKContainer<T>(size) 
 {
   for(int i = 0; i < size; i++)
-    data[i] = source[i];
+    this->data[i] = source[i];
   BuildHeap();
 }
 
@@ -94,13 +94,13 @@
 void VDKHeap<T>::Heapify(int i, int heapsize)
 {
   int l = left(i), r = right(i), largest = i;
-  if( (l < heapsize) && (data[l] > data[i])) largest = l;
-  if( (r < heapsize) && (data[r] > data[largest])) largest = r;
+  if( (l < heapsize) && (this->data[l] > this->data[i])) largest = l;
+  if( (r < heapsize) && (this->data[r] > this->data[largest])) largest = r;
   if(largest != i)
     {
-      T temp = data[i];
-      data[i] = data[largest];
-      data[largest] = temp;
+      T temp = this->data[i];
+      this->data[i] = this->data[largest];
+      this->data[largest] = temp;
       Heapify(largest,heapsize);
     }
 }
@@ -109,21 +109,21 @@
 template <class T>
 void VDKHeap<T>::BuildHeap(void)
 {
-  for (int i = (size()-1)/2 ; i >= 0; i--)	
-    Heapify(i,size());
+  for (int i = (this->size()-1)/2 ; i >= 0; i--)	
+    Heapify(i,this->size());
 }
 
 // HEAPSORT
 template <class T>
 void VDKHeap<T>::Sort(void)
 {
-  int heapsize = size();
+  int heapsize = this->size();
   int i = heapsize-1;
   for(; i > 0; i--)
     {
-      T temp = data[0];
-      data[0] = data[i];
-      data[i] = temp;
+      T temp = this->data[0];
+      this->data[0] = this->data[i];
+      this->data[i] = temp;
       heapsize--;
       Heapify(0,heapsize);
     }
