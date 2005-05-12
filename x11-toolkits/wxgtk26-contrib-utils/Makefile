# New ports collection makefile for:	wxgtk26-contrib-utils
# Date created:         		June 27, 2004
# Whom:					fjoe@FreeBSD.ORG
#
# $FreeBSD$
#

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	The wxWidgets GUI toolkit utils

.if defined(WITH_UNICODE)
WXGTK_FLAVOR=	gtk2-unicode-contrib-utils
LIB_DEPENDS=	wx_gtk2u_stc-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26-unicode-contrib
.else
WXGTK_FLAVOR=	gtk2-contrib-utils
LIB_DEPENDS=	wx_gtk2_stc-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26-contrib
.endif

BUILD_WRKSRC=	${WRKSRC}/contrib/utils
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MASTERDIR=	${.CURDIR}/../wxgtk26

.include "${MASTERDIR}/Makefile"
