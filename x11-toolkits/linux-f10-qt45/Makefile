# $FreeBSD$

PORTNAME=	${LINUX_NAME}45
PORTVERSION=	4.5.3
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	http://archives.fedoraproject.org/pub/archive/fedora/linux/updates/10/i386/ \
		http://archives.fedoraproject.org/pub/archive/fedora/linux/updates/10/SRPMS/
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of QT4 (Linux Fedora 10)

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	fontconfig libmng png
LINUX_NAME=	qt
LINUX_DIST_VER=	10
RPMVERSION=	9.fc10
USE_LDCONFIG=	yes
PLIST=		${PKGDIR}/pkg-plist.${LINUX_RPM_ARCH}

.include <bsd.port.mk>
