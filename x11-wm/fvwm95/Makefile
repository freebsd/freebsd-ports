# New ports collection makefile for:	fvwm95-2
# Version required:	2.0.41f
# Date created:		Wed Apr 10 21:57:17 MET DST 1996
# Whom:			Andreas Klemm <andreas@knobel.gun.de>
#
# $Id: Makefile,v 1.1.1.1 1996/04/12 07:41:56 asami Exp $
#

DISTNAME=	fvwm95-2.0.41f
CATEGORIES+=	x11
MASTER_SITES=	ftp://mitac11.uia.ac.be/pub/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andreas@knobel.gun.de

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
#XMKMF=		xmkmf
#ALL_TARGET=	Makefiles all

#post-configure:
#	@ln ${WRKSRC}/fvwm/fvwm2.man ${WRKSRC}/fvwm/fvwm95-2.man

post-install:
	@echo "installing default system.fvwmrc file..."
	@mv -f ${PREFIX}/lib/X11/fvwm95-2/system.fvwmrc \
		${PREFIX}/lib/X11/fvwm95-2/system.fvwmrc.old
	${INSTALL} -c -m 444 ${WRKSRC}/example.fvwm2rc95 \
		${PREFIX}/lib/X11/fvwm95-2/system.fvwmrc
	@echo "installing icons in ${PREFIX}/lib/X11/fvwm95-2/..."
	@mkdir -p ${PREFIX}/lib/X11/fvwm95-2/icons
	${INSTALL} -c -m 444 ${WRKSRC}/icons/*.x?m \
		${PREFIX}/lib/X11/fvwm95-2/icons
	${INSTALL} -c -m 444 ${FILESDIR}/*.x?m \
		${PREFIX}/lib/X11/fvwm95-2/icons
	@mkdir -p ${PREFIX}/lib/X11/fvwm95-2/mini-icons
	${INSTALL} -c -m 444 ${WRKSRC}/mini-icons/*.x?m \
		${PREFIX}/lib/X11/fvwm95-2/mini-icons
	@echo ""
	@echo "=========== INSTALLATION INSTRUCTIONS ======================"
	@echo "To use fvwm95-2 you have to execute the following command:"
	@echo ""
	@echo "    cp ${PREFIX}/lib/X11/fvwm95-2/system.fvwmrc ~/.fvwm2rc95"
	@echo ""
	@echo "That's it - have fun"
	@echo ""
	@echo "Andreas Klemm"
	@echo ""
	@echo ""

.include <bsd.port.mk>
