# Bipolar Junction NPN Transistor

NOTE: pwm pin uses pulse to send signal and thus it goes on 5v and off 0v in a frequency so we can never achieve amplification.

To turn on you have to apply a small volt between base and emitter to forward bias the junction

arduino provides a max 5v and emitter is connected to ground:-

`Vbe = Vb - Ve`

for silicon bjt npn we need to supply 0.7v to base to allow current to flow from base to emitter that controls the flow of collecter current.

Here B is beta which is transistor current gain:-

`Ic = B * Ib`

# Conditions

## Cut-off

**Vbc** and **Vbe** are reversed biased
`Vbe < 0.7v` or `Ib = 0`

## Active Amplification

Vbe forward and Vbc reversed
`Vbe = ~0.7v` and `Vc > Vb`

## Saturation 

vbe is forward and vbc is forward biased

`Vbe = ~0.7v` and `Vce = 0.2v`

---

Given:
Vcc = 14v
Vbb =7v
Icc = 1600ma
Ibb = 40ma

light up a 2v led that can only handle 20ma

Sol:

First find B beta, Ic is limited to 20ma due to led safety net, and B is taken as 10 to ensure saturation
Ic = B * Ib
20 = 10 * Ib
Ib = 2ma

we will use 5ma to ensure saturation

assumed saturation provides
Vce = 0.2v
Vbe = 0.7v

using Ic = 20ma for led safety
Rc = {(Vcc - Vce) - Vl} / (Ic)
= 14 - 0.2 - 2 / 0.020
= 590 ohm

using a rounded 600 ohm current through led
Il = 14 - 0.2 - 2 / 600 = 19.7ma which will cause low brightness

using Ib = 5ma for npn safety
Rb = (Vbb - Vbe) / (Ib)
= 7 - 0.7 / 0.005
= 1260 ohm

using 1200 ohm
Ib = 7 - 0.7 / 1200 = 5.3ma

saturation check (check with real B beta around 100)
Ic = B * Ib
Ib min = 19.7/100 = 0.197ma
if Ib min is passed it will be multiplied by 100 reaching its edge of saturation, our 5.3ma is much higher so saturation is guranteed 

Ie = 19.7 + 5.3 = 25ma

Then we check power discipation of npn
Pn = Pc + Pb

Pc = Ic x Vce = 4mw
Pb = Ib x Vbe = 4mw

Pn = 4 + 4 = 8 mW

max Pn is 350mw and thus its safe from frying.