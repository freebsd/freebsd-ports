# New ports collection makefile for:	wxgtk2-utils-devel
# Date created:         		June 27, 2004
# Whom:					fjoe@FreeBSD.ORG
#
# $FreeBSD$
#

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	The wxWidgets GUI toolkit utils (devel version)

.if defined(WITH_UNICODE)
WXGTK_FLAVOR=	gtk2-unicode-utils
LIB_DEPENDS=	wx_gtk2u_stc-2.5.3:${PORTSDIR}/x11-toolkits/wxgtk2-unicode-contrib-devel
.else
WXGTK_FLAVOR=	gtk2-utils
LIB_DEPENDS=	wx_gtk2_stc-2.5.3:${PORTSDIR}/x11-toolkits/wxgtk2-contrib-devel
.endif

BUILD_WRKSRC=	${WRKSRC}/contrib/utils
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MASTERDIR=	${.CURDIR}/../wxgtk2-devel

.include "${MASTERDIR}/Makefile"
