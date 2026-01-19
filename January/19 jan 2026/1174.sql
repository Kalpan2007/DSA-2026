# Write your MySQL query statement below
SELECT 
    COALESCE(
        ROUND(
        AVG(CASE WHEN order_date=customer_pref_delivery_date THEN 1 ELSE 0 END)*100
        ,2
    )
        ,0.00) AS immediate_percentage
FROM delivery d
JOIN(
    SELECT customer_id, MIN(order_date) AS first_order
    FROM delivery
    GROUP BY customer_id
) f
    ON d.customer_id=f.customer_id
    AND d.order_date=f.first_order