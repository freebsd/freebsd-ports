# New ports collection makefile for:	gtstarter
# Date created:				15 April 2004
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	gtstarter
PORTVERSION=	0.4.6.2
CATEGORIES=	x11 gnome
MASTER_SITES=	http://webonaut.com/distfiles/${PORTNAME}/

MAINTAINER=	klammer@webonaut.com
COMMENT=	Start gnome-terminal from a list of configured profiles (incl. Applet)

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_GNOME=	pygnome2 pygnomeextras gnomeprefix

do-build:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${PREFIX}|g' \
		${WRKSRC}/*.py ${WRKSRC}/*.server
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
		${PREFIX}/libexec/${PORTNAME}/
	@${INSTALL_SCRIPT} ${WRKSRC}/*.py* \
		${PREFIX}/libexec/${PORTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${PREFIX}/share/gnome/applications/
	@${INSTALL_DATA} ${WRKSRC}/*.server \
		${PREFIX}/libdata/bonobo/servers/
	@${LN} -sf ${PREFIX}/libexec/${PORTNAME}/${PORTNAME} \
		${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
