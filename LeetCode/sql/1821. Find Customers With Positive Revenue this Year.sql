SELECT customer_id
FROM Customers
WHERE Customers.year = '2021'
  AND Customers.revenue > 0
GROUP BY Customers.customer_id