# resources : https://researchhubs.com/post/computing/algorithm-1/quick-find.html

# Disjoint Set Union (Union-Find)

---

## 📌 What is Quick Find?

**Quick Find** is one of the first approaches to solve the **Dynamic Connectivity** problem using the **Disjoint Set Union (DSU)** data structure.

---

## ⚡ How does Quick Find work?

- **Goal:** To check if two elements belong to the same group or not.
- **Structure:** We maintain an array `id[]` where each element points to its group ID.
- **Union:** When we union two elements, we update all elements of the second group to have the same ID as the first.
- **Find:** To check if two elements are in the same group, we simply check if their `id[]` values match.

---

## 📈 Performance:
- **Find:** O(1) – very fast!
- **Union:** O(n) – slow because we need to update every element in the second group.

---

## 🚧 Drawbacks:
- **Quick Find is slow for large datasets** because the `union()` operation takes time proportional to the number of elements in the group.

---

## 🔗 When to use?
- **Quick Find** is simple but works best for small problems or where union operations aren’t frequent.

---

