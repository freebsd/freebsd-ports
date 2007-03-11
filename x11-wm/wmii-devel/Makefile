# New ports collection makefile for:	wmii-devel
# Date created:		2 June 2005
# Whom:			Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmii
PORTVERSION=	3.5.${CHANGESET}
CATEGORIES=	x11-wm
MASTER_SITES=	CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A dynamic minimalist window manager

LIB_DEPENDS=	ixp.0:${PORTSDIR}/devel/libixp
RUN_DEPENDS=	dmenu:${PORTSDIR}/x11/dmenu \
		${LOCALBASE}/9/bin/rc:${PORTSDIR}/devel/9base

CHANGESET=	2010
CONFLICTS=	wmii-3.[0-46-9]* wmii-3.5.1*
USE_XLIB=	yes
USE_BZIP2=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" X11LIB="${X11BASE}/lib" \
		X11INC="${X11BASE}/include" CC="${CC}" \
		MANPREFIX="${MANPREFIX}/man"

MAN1=		wmii.1 wmiiloop.1 wmiir.1 wmiiwm.1

post-patch:
	@${REINPLACE_CMD} -e '/-[LI]/s|PREFIX|LOCALBASE|g;/^[CL].*FLAGS/s|=|+=|' ${WRKSRC}/config.mk
	@${REINPLACE_CMD} -e '/cp -f wmiiwm/s|cp -f|${INSTALL_PROGRAM}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|$$PLAN9|${LOCALBASE}/9|' ${WRKSRC}/wmii9rc
	@${REINPLACE_CMD} -e 's|$$PLAN9|${LOCALBASE}/9|;1s|/.*|${LOCALBASE}/9/bin/rc -v|' ${WRKSRC}/rc/rc.wmii
	@${REINPLACE_CMD} -e '/strlcat/d' ${WRKSRC}/wmii.h
	@${FIND} ${WRKSRC}/ -name \*.bak -delete

.include <bsd.port.mk>
