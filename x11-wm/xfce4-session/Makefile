# New ports collection makefile for:	xfce4-session
# Date created:		2003-10-30
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-session
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	x11-wm xfce
MASTER_SITES=	ftp://ftp.unix-ag.org/user/bmeurer/xfce4/xfce4-session/ \
		http://echobase.homeunix.net/~bmeurer/tmp/xfce4-session/

MAINTAINER=	matt@rimasec.net
COMMENT=	XFce 4 Session Manager

BUILD_DEPENDS=	xfce-mcs-manager:${PORTSDIR}/sysutils/xfce4-mcs-manager
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.1:${PORTSDIR}/x11-toolkits/libxfce4gui

USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

MAN1=		xfce4-session.1 xfce4-shutdown.1

DOCS=		AUTHORS NEWS README TODO

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
