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
),
AllProducts AS (
    SELECT DISTINCT product_id
    FROM Prices
)
SELECT
    ap.product_id,
    ROUND(
        IFNULL(SUM(sr.revenue) / SUM(sr.units), 0),
        2
    ) AS average_price
FROM AllProducts ap
LEFT JOIN SalesRevenue sr
    ON ap.product_id = sr.product_id
GROUP BY ap.product_id;
