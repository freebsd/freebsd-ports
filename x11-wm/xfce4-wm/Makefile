# New ports collection makefile for:	xfwm4
# Date created:		August 14, 2002
# Whom:			James Earl <jamesearl@shaw.ca>
#
# $FreeBSD$
#

PORTNAME=	xfwm4
PORTVERSION=	020724
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://belnet.dl.sourceforge.net/sourceforge/xfce/ \
		http://unc.dl.sourceforge.net/sourceforge/xfce/
MASTER_SITE_SUBDIR=	xfce

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk-2.0 based window manager part of the XFCE project

USE_GNOME=	gtk20
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' ${WRKSRC}/src/pixmap.c

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xfwm4 ${PREFIX}/share/examples/xfwm4
	${MKDIR} ${PREFIX}/share/examples/xfwm4

	${INSTALL_MAN} ${WRKSRC}/README ${WRKSRC}/TODO ${PREFIX}/share/doc/xfwm4
	${INSTALL_MAN} ${WRKSRC}/example.xfwm4rc ${WRKSRC}/example.gtkrc-2.0 ${PREFIX}/share/examples/xfwm4

	@${ECHO} "===>   Configuration:" ;
	@${ECHO} "        - Example rc files installed in ${PREFIX}/share/examples/${PORTNAME}" ;
	@${ECHO} "        - Refer to documentation in ${PREFIX}/share/doc/${PORTNAME}" ;
	@${ECHO} "        - For online help see: http://xfce.sourceforge.net" ;
.endif

.include <bsd.port.mk>
