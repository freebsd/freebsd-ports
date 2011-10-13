# New ports collection makefile for:	stjerm
# Date created:		2011-03-25
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	stjerm
PORTVERSION=	0.15
CATEGORIES=	x11
MASTER_SITES=	http://stjerm-terminal.googlecode.com/files/

MAINTAINER=	lichray@gmail.com
COMMENT=	A GTK+-based quake-like terminal emulator

USE_AUTOTOOLS=	aclocal autoheader automake
AUTOMAKE_ARGS=	--add-missing
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} \
		-I${LOCALBASE}/share/aclocal
USE_GNOME=	vte gtk20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN8=		stjerm.8
LICENSE_FILE=	${WRKSRC}/COPYING
PLIST_FILES=	bin/stjerm

.include <bsd.port.mk>
