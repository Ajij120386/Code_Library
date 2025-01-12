
   //Modified version of solution submitted by yashiwach
   //Mostly the same, but removes calls to vector.erase() and unique()
   //in exchange for an extra if statement per equality
   vector<int> answer;
   sort(nums1.begin(), nums1.end());
   sort(nums2.begin(), nums2.end());
   int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();

   while (i < n1 && j < n2){
       if (nums1[i] < nums2[j]) i++;
       else if (nums2[j] < nums1[i]) j++;
       else {
           //note that you can also use answer.back() instead of a
           //separate int variable (in this case, the last variable)
           if (answer.empty() || nums1[i] != answer.back()) answer.push_back(nums1[i]);
           i++; j++;
       }
   }

   return answer;
}
