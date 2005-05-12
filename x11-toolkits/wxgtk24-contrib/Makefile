# New ports collection makefile for:	wxgtk-contrib
# Date created:         		November 4, 2003
# Whom:					fjoe@FreeBSD.ORG
#
# $FreeBSD$
#

PORTREVISION=	3

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	The wxWidgets GUI toolkit contributed libraries

WXGTK_FLAVOR=	gtk2-contrib
MASTERDIR=	${.CURDIR}/../wxgtk24
LIB_DEPENDS+=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24

BUILD_WRKSRC=	${WRKSRC}/contrib/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include "${MASTERDIR}/Makefile"
