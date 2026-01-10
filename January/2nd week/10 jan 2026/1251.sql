# Write your MySQL query statement below



WITH SalesRevenue AS (
    SELECT
        u.product_id,
        u.units,
        p.price,
        u.units * p.price AS revenue
    FROM UnitsSold u
    JOIN Prices p
      ON u.product_id = p.product_id
     AND u.purchase_date BETWEEN p.start_date AND p.end_date
)
SELECT
    product_id,
    ROUND(IFNULL(SUM(revenue) / SUM(units), 0), 2) AS average_price
FROM SalesRevenue
GROUP BY product_id;

