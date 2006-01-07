# New ports collection makefile for:	xnee
# Date created:				27 May 2002
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	xnee
PORTVERSION=	2.03
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Xnee-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X events recorder and player

USE_X_PREFIX=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doc

INFO=		xnee
PLIST_FILES=	bin/cnee \
		lib/libxnee.a \
		share/Xnee/example1.xns \
		share/Xnee/simple_bash.sh \
		share/Xnee/xnee.sh
PLIST_DIRS=	share/Xnee

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk20}!=""
USE_GNOME+=	gtk20
PLIST_FILES+=	bin/gnee
PKGNAMESUFFIX=	-gtk
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/bin|!#!${LOCALBASE}/bin|g' \
		${WRKSRC}/examples/simple_bash.sh

post-install:
	cd ${WRKSRC}/doc && makeinfo --no-split xnee.texi
	${INSTALL_DATA} ${WRKSRC}/doc/xnee.info ${PREFIX}/${INFO_PATH}

.include <bsd.port.post.mk>
