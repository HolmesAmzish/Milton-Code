"""
program: plot the power_law function
date: 2024-10-13
author: cacc
"""

import numpy as np
import matplotlib.pyplot as plt

c0 = 1
beta = 3

def p_k(k, c0, beta):
    return c0 * k**(-beta)

def ln_p_k(k, c0, beta):
    return np.log(c0 * k**(-beta))

k1 = np.arange(1, 11, dtype=float)
p_k1 = p_k(k1, c0, beta)
ln_p_k1 = ln_p_k(k1, c0, beta)

k2 = np.arange(1, 101, dtype=float)
p_k2 = p_k(k2, c0, beta)
ln_p_k2 = ln_p_k(k2, c0, beta)

plt.figure(figsize=(12, 6))

plt.subplot(2, 2, 1)
plt.plot(k1, p_k1, label='k in [1, 10]', color='red')
plt.title('p(k) = c0 * k^(-beta)')
plt.xlabel('k')
plt.ylabel('p(k)')
plt.legend()

plt.subplot(2, 2, 2)
plt.plot(k2, p_k2, label='k in [1, 100]', color='red')
plt.title('p(k) = c0 * k^(-beta)')
plt.xlabel('k')
plt.ylabel('p(k)')
plt.legend()

plt.subplot(2, 2, 3)
plt.plot(k1, ln_p_k1, label='k in [1, 10]', color='blue')
plt.title('Ln(p(k)) = Ln(c0 * k^(-beta))')
plt.xlabel('k')
plt.ylabel('Ln(p(k))')
plt.legend()

plt.subplot(2, 2, 4)
plt.plot(k2, ln_p_k2, label='k in [1, 100]', color='blue')
plt.title('Ln(p(k)) = Ln(c0 * k^(-beta))')
plt.xlabel('k')
plt.ylabel('Ln(p(k))')
plt.legend()

plt.tight_layout()
plt.show()
